#ifndef DATABASE_SQLITE_H
#define DATABASE_SQLITE_H

#include <sqlite3.h>
#include "report.h"

sqlite3* openDatabase();
void closeDatabase(sqlite3 *db);

int insertReport(sqlite3 *db, Report report);
void viewReportsSQLite(sqlite3 *db);
void searchReportsSQLite(sqlite3 *db, const char *keyword);

#endif