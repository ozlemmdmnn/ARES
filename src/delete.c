#include <stdio.h>

#include "../include/delete.h"
#include "../include/database_sqlite.h"

void deleteReport()
{
    int id;

    printf("\nEnter Report ID to delete: ");
    scanf("%d", &id);

    while(getchar()!='\n');

    sqlite3 *db = openDatabase();

    if(db == NULL)
        return;

    if(deleteReportSQLite(db,id))
        printf("\nReport deleted successfully.\n");
    else
        printf("\nReport not found.\n");

    closeDatabase(db);
}