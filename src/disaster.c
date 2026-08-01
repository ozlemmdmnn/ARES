#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../include/disaster.h"
#include "../include/report.h"
#include "../include/database_sqlite.h"

void reportDisaster()
{
    Report report;

    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);

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
    while(getchar() != '\n');

    printf("Description: ");
    fgets(report.description, sizeof(report.description), stdin);
    report.description[strcspn(report.description, "\n")] = '\0';

    printf("Reporter: ");
    fgets(report.reporter, sizeof(report.reporter), stdin);
    report.reporter[strcspn(report.reporter, "\n")] = '\0';

    strcpy(report.status, "Pending");

    sqlite3 *db = openDatabase();

    if(db == NULL)
        return;

    if(insertReport(db, report))
        printf("\nReport saved successfully!\n");
    else
        printf("\nReport could not be saved!\n");

    closeDatabase(db);
}