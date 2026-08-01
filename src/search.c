#include <stdio.h>
#include <string.h>
#include "../include/search.h"

void searchReports()
{
    FILE *file;
    char line[256];
    char report[2000] = "";
    char keyword[50];

    int found = 0;
    int match = 0;

    printf("\n========== SEARCH REPORT ==========\n");
    printf("Enter city or disaster type: ");

    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    file = fopen("reports.txt", "r");

    if (file == NULL)
    {
        printf("\nNo reports found.\n");
        return;
    }

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "=====================================") != NULL)
        {
            if (match)
            {
                printf("\n%s", report);
                found = 1;
            }

            strcpy(report, line);
            match = 0;
        }
        else
        {
            strcat(report, line);

            if (strstr(line, keyword) != NULL)
                match = 1;
        }
    }

    if (match)
    {
        printf("\n%s", report);
        found = 1;
    }

    fclose(file);

    if (!found)
    {
        printf("\nNo matching report found.\n");
    }
}