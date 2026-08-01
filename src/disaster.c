#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../include/disaster.h"
#include "../include/report.h"

void reportDisaster()
{
    static int reportID = 1;

    Report report;
    FILE *file;

    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

    report.id = reportID;

    strftime(report.date, sizeof(report.date), "%d/%m/%Y", currentTime);
    strftime(report.time, sizeof(report.time), "%H:%M", currentTime);

    printf("\n========== DISASTER REPORT ==========\n");

    printf("Disaster Type: ");
    fgets(report.disasterType, sizeof(report.disasterType), stdin);
    report.disasterType[strcspn(report.disasterType, "\n")] = '\0';

    printf("City: ");
    fgets(report.city, sizeof(report.city), stdin);
    report.city[strcspn(report.city, "\n")] = '\0';

    printf("District: ");
    fgets(report.district, sizeof(report.district), stdin);
    report.district[strcspn(report.district, "\n")] = '\0';

    printf("Severity (1-10): ");
    scanf("%d", &report.severity);
    while (getchar() != '\n');

    printf("Description: ");
    fgets(report.description, sizeof(report.description), stdin);
    report.description[strcspn(report.description, "\n")] = '\0';

    printf("Reporter: ");
    fgets(report.reporter, sizeof(report.reporter), stdin);
    report.reporter[strcspn(report.reporter, "\n")] = '\0';

    strcpy(report.status, "Pending");

    file = fopen("reports.txt", "a");

    if (file == NULL)
    {
        printf("\nError creating report file!\n");
        return;
    }

    fprintf(file, "=====================================\n");
    fprintf(file, "Report ID      : %d\n", report.id);
    fprintf(file, "Date           : %s\n", report.date);
    fprintf(file, "Time           : %s\n", report.time);
    fprintf(file, "Disaster Type  : %s\n", report.disasterType);
    fprintf(file, "City           : %s\n", report.city);
    fprintf(file, "District       : %s\n", report.district);
    fprintf(file, "Severity       : %d\n", report.severity);
    fprintf(file, "Description    : %s\n", report.description);
    fprintf(file, "Reporter       : %s\n", report.reporter);
    fprintf(file, "Status         : %s\n", report.status);
    fprintf(file, "=====================================\n\n");

    fclose(file);

    reportID++;

    printf("\nReport saved successfully!\n");
}