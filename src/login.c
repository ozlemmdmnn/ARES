#include <stdio.h>
#include <string.h>

#include "../include/login.h"
#include "../include/database_sqlite.h"

char currentRole[50] = "";

int login()
{
    char username[50];
    char password[50];

    printf("\n========== LOGIN ==========\n");

    printf("Username: ");
    scanf("%49s", username);

    printf("Password: ");
    scanf("%49s", password);

    sqlite3 *db = openDatabase();

    if(db == NULL)
        return 0;

    if(loginSQLite(db, username, password, currentRole))
    {
        closeDatabase(db);

        printf("\nLogin Successful!\n");
        printf("Role : %s\n", currentRole);

        return 1;
    }

    closeDatabase(db);

    printf("\nInvalid username or password!\n");

    return 0;
}