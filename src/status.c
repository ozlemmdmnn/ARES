#include <stdio.h>
#include <string.h>

#include "../include/status.h"
#include "../include/database_sqlite.h"

void updateStatus()
{
    int id;
    char status[30];

    printf("\n========== UPDATE STATUS ==========\n");

    printf("Report ID : ");
    scanf("%d",&id);

    while(getchar()!='\n');

    printf("New Status : ");
    fgets(status,sizeof(status),stdin);

    status[strcspn(status,"\n")]='\0';

    sqlite3 *db=openDatabase();

    if(db==NULL)
        return;

    if(updateStatusSQLite(db,id,status))
        printf("\nStatus updated successfully.\n");
    else
        printf("\nReport not found.\n");

    closeDatabase(db);
}