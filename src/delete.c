#include <stdio.h>
#include <string.h>
#include "../include/delete.h"

void deleteReport()
{
    int id;
    char line[256];

    FILE *file = fopen("reports.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL)
    {
        printf("\nNo reports found.\n");
        return;
    }

    printf("\n========== DELETE REPORT ==========\n");
    printf("Enter Report ID: ");
    scanf("%d", &id);
    while(getchar()!='\n');

    int deleteMode = 0;
    int deleted = 0;

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "Report ID"))
        {
            int currentID;

            sscanf(line, "Report ID      : %d", &currentID);

            if (currentID == id)
            {
                deleteMode = 1;
                deleted = 1;
                continue;
            }
            else
            {
                deleteMode = 0;
            }
        }

        if (!deleteMode)
            fputs(line, temp);

        if (deleteMode && strstr(line, "====================================="))
            deleteMode = 0;
    }

    fclose(file);
    fclose(temp);

    remove("reports.txt");
    rename("temp.txt", "reports.txt");

    if (deleted)
        printf("\nReport deleted successfully.\n");
    else
        printf("\nReport not found.\n");
}