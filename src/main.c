#include <stdio.h>

int main()
{
    int choice;

    while (1)
    {
        printf("\n=====================================\n");
        printf("              ARES v0.1\n");
        printf("Artificial Response & Emergency System\n");
        printf("=====================================\n");

        printf("\n1. Login\n");
        printf("2. Report Disaster\n");
        printf("3. Risk Analysis\n");
        printf("4. Exit\n");

        printf("\nSelect an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\n[Login Module]\n");
                break;

            case 2:
                printf("\n[Disaster Report Module]\n");
                break;

            case 3:
                printf("\n[Risk Analysis Module]\n");
                break;

            case 4:
                printf("\nClosing ARES...\n");
                return 0;

            default:
                printf("\nInvalid option!\n");
        }
    }
}