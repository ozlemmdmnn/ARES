#include "../include/resource.h"
#include <stdio.h>
#include "../include/database.h"


#include "../include/menu.h"
#include "../include/login.h"
#include "../include/disaster.h"
#include "../include/risk.h"

int main()
{
    int choice;

    while (1)
    {
        showMenu();

        printf("\nSelect an option: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice)
        {
            case 1:
                login();
                break;

            case 2:
                reportDisaster();
                break;

            case 3:
    riskAnalysis();
    break;

            case 4:
    resourceManagement();
    break;
            case 5:
    viewReports();
    break;

case 6:
    printf("\nClosing ARES...\n");
    return 0;

            default:
                printf("\nInvalid option!\n");
        }
    }

    return 0;
}
