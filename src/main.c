#include <stdio.h>

#include "../include/menu.h"
#include "../include/login.h"
#include "../include/disaster.h"
#include "../include/risk.h"
#include "../include/resource.h"
#include "../include/database.h"
#include "../include/search.h"
#include "../include/delete.h"
#include <string.h>
#include "../include/status.h"
#include "../include/statistics.h"
int main()
{
    int choice;
    int isLoggedIn = 0;

    while (1)
    {
        showMenu();

        printf("\nSelect an option: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input!\n");

            while (getchar() != '\n');

            continue;
        }

        while (getchar() != '\n');

       

        switch (choice)
        {case 1:
    if (login())
    {
        isLoggedIn = 1;
        printf("\nAccess Granted!\n");
    }
    else
    {
        printf("\nAccess Denied!\n");
    }
    break;
          case 2:
    if (!isLoggedIn)
    {
        printf("\nPlease login first!\n");
        break;
    }

    reportDisaster();
    break;
            case 3:
            if (!isLoggedIn)
{
    printf("\nPlease login first!\n");
    break;
}
            case 4:
               if (!isLoggedIn)
{
    printf("\nPlease login first!\n");
    break;
}
case 5:
   if (!isLoggedIn)
{
    printf("\nPlease login first!\n");
    break;
}
    case 6:
    if (!isLoggedIn)
{
    printf("\nPlease login first!\n");
    break;
}

  case 7:
    if (!isLoggedIn)
    {
        printf("\nPlease login first!\n");
        break;
    }

    if (strcmp(currentRole, "Admin") != 0)
    {
        printf("\nAccess Denied! Only Admin can delete reports.\n");
        break;
    }

    deleteReport();
    break;


case 8:
    showStatistics();
    break;

case 9:
    printf("\nClosing ARES...\n");
    return 0;
        }
    }

    return 0;
}