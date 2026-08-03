#include <stdio.h>

#include "../include/database.h"
#include "../include/database_sqlite.h"

void viewReports()
{
    sqlite3 *db = openDatabase();

    if (db == NULL)
        return;

    viewReportsSQLite(db);

    closeDatabase(db);
}