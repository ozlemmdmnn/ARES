#include <stdio.h>
#include <string.h>

#include "../include/edit.h"
#include "../include/report.h"
#include "../include/database_sqlite.h"

void editReport()
{
    Report report;

    printf("\n========== EDIT REPORT ==========\n");

    printf("Report ID: ");
    scanf("%d",&report.id);
    while(getchar()!='\n');

    printf("New City: ");
    fgets(report.city,sizeof(report.city),stdin);
    report.city[strcspn(report.city,"\n")]='\0';

    printf("New District: ");
    fgets(report.district,sizeof(report.district),stdin);
    report.district[strcspn(report.district,"\n")]='\0';

    printf("New Severity (1-10): ");
    scanf("%d",&report.severity);
    while(getchar()!='\n');

    printf("New Description: ");
    fgets(report.description,sizeof(report.description),stdin);
    report.description[strcspn(report.description,"\n")]='\0';

    printf("New Status: ");
    fgets(report.status,sizeof(report.status),stdin);
    report.status[strcspn(report.status,"\n")]='\0';

    sqlite3 *db = openDatabase();

    if(db==NULL)
        return;

    if(editReportSQLite(db,report))
        printf("\nReport updated successfully.\n");
    else
        printf("\nReport not found.\n");

    closeDatabase(db);
}