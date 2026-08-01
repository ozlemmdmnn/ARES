#include <stdio.h>
#include <string.h>

#include "../include/search.h"
#include "../include/database_sqlite.h"

void searchReports()
{
    char keyword[50];

    printf("\nSearch (City / Disaster Type): ");
    fgets(keyword,sizeof(keyword),stdin);

    keyword[strcspn(keyword,"\n")]='\0';

    sqlite3 *db=openDatabase();

    if(db==NULL)
        return;

    searchReportsSQLite(db,keyword);

    closeDatabase(db);
}