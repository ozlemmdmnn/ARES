#include <stdio.h>
#include <sqlite3.h>

#include "../include/database_sqlite.h"

sqlite3* openDatabase()
{
    sqlite3 *db;

    if (sqlite3_open("ares.db", &db) != SQLITE_OK)
    {
        printf("Database connection failed!\n");
        return NULL;
    }

    return db;
}

void closeDatabase(sqlite3 *db)
{
    sqlite3_close(db);
}

int insertReport(sqlite3 *db, Report report)
{
    char sql[1000];

    sprintf(sql,
            "INSERT INTO reports(date,time,disasterType,city,district,severity,description,reporter,status) "
            "VALUES('%s','%s','%s','%s','%s',%d,'%s','%s','%s');",
            report.date,
            report.time,
            report.disasterType,
            report.city,
            report.district,
            report.severity,
            report.description,
            report.reporter,
            report.status);

    char *error = NULL;

    if (sqlite3_exec(db, sql, NULL, NULL, &error) != SQLITE_OK)
    {
        printf("SQLite Error: %s\n", error);
        sqlite3_free(error);
        return 0;
    }

    return 1;
}

void viewReportsSQLite(sqlite3 *db)
{
    sqlite3_stmt *stmt;

    const char *sql =
        "SELECT id, date, time, disasterType, city, district, severity, reporter, status FROM reports;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
    {
        printf("Query Error!\n");
        return;
    }

    printf("\n========================================\n");
    printf("            ARES REPORTS\n");
    printf("========================================\n");

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        printf("ID          : %d\n", sqlite3_column_int(stmt, 0));
        printf("Date        : %s\n", sqlite3_column_text(stmt, 1));
        printf("Time        : %s\n", sqlite3_column_text(stmt, 2));
        printf("Type        : %s\n", sqlite3_column_text(stmt, 3));
        printf("City        : %s\n", sqlite3_column_text(stmt, 4));
        printf("District    : %s\n", sqlite3_column_text(stmt, 5));
        printf("Severity    : %d\n", sqlite3_column_int(stmt, 6));
        printf("Reporter    : %s\n", sqlite3_column_text(stmt, 7));
        printf("Status      : %s\n", sqlite3_column_text(stmt, 8));
        printf("----------------------------------------\n");
    }

    sqlite3_finalize(stmt);
}
void searchReportsSQLite(sqlite3 *db, const char *keyword)
{
    sqlite3_stmt *stmt;

    const char *sql =
    "SELECT id,date,time,disasterType,city,district,severity,status "
    "FROM reports "
    "WHERE city LIKE ? OR disasterType LIKE ?;";

    if(sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK)
    {
        printf("Query Error!\n");
        return;
    }

    char search[100];
    sprintf(search,"%%%s%%",keyword);

    sqlite3_bind_text(stmt,1,search,-1,SQLITE_STATIC);
    sqlite3_bind_text(stmt,2,search,-1,SQLITE_STATIC);

    printf("\n========== SEARCH RESULTS ==========\n\n");

    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        printf("ID        : %d\n",sqlite3_column_int(stmt,0));
        printf("Date      : %s\n",sqlite3_column_text(stmt,1));
        printf("Time      : %s\n",sqlite3_column_text(stmt,2));
        printf("Type      : %s\n",sqlite3_column_text(stmt,3));
        printf("City      : %s\n",sqlite3_column_text(stmt,4));
        printf("District  : %s\n",sqlite3_column_text(stmt,5));
        printf("Severity  : %d\n",sqlite3_column_int(stmt,6));
        printf("Status    : %s\n",sqlite3_column_text(stmt,7));
        printf("-----------------------------------\n");
    }

    sqlite3_finalize(stmt);
}