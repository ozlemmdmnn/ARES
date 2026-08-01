#include <stdio.h>
#include "../include/database.h"

void viewReports()
{
    FILE *file;
    char line[256];

    file = fopen("reports.txt", "r");

    if (file == NULL)
    {
        printf("\nNo reports found.\n");
        return;
    }

    printf("\n========== SAVED REPORTS ==========\n\n");

    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
}