#include <stdio.h>

#include "../include/statistics.h"
#include "../include/database_sqlite.h"

void showStatistics()
{
    sqlite3 *db = openDatabase();

    if(db == NULL)
        return;

    showStatisticsSQLite(db);

    closeDatabase(db);
}