#include <stdio.h>
#include <string.h>
#include "../include/disaster.h"

void reportDisaster()
{
    char disasterType[50];
    char city[50];
    char description[200];

    FILE *file;

    printf("\n========== DISASTER REPORT ==========\n");

    printf("Disaster Type: ");
    fgets(disasterType, sizeof(disasterType), stdin);
    if (strlen(disasterType) == 1)
        fgets(disasterType, sizeof(disasterType), stdin);

    disasterType[strcspn(disasterType, "\n")] = '\0';

    printf("City: ");
    fgets(city, sizeof(city), stdin);
    city[strcspn(city, "\n")] = '\0';

    printf("Description: ");
    fgets(description, sizeof(description), stdin);
    description[strcspn(description, "\n")] = '\0';

    file = fopen("reports.txt", "a");

    if (file == NULL)
    {
        printf("Error creating report file!\n");
        return;
    }

    fprintf(file, "------------------------------\n");
    fprintf(file, "Disaster Type: %s\n", disasterType);
    fprintf(file, "City: %s\n", city);
    fprintf(file, "Description: %s\n\n", description);

    fclose(file);

    printf("\nReport saved successfully!\n");
}