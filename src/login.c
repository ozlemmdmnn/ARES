#include <stdio.h>
#include <string.h>
#include "../include/login.h"

char currentRole[50] = "";


int login()
{
    char currentRole[50];
    char username[50];
    char password[50];

    char fileUsername[50];
    char filePassword[50];
    char role[50];

    int loginSuccess = 0;

    FILE *file = fopen("users.txt", "r");

    if (file == NULL)
    {
        printf("\nError: users.txt could not be opened!\n");
        return 0;
    }

    printf("\n========== LOGIN ==========\n");

    printf("Username: ");
    scanf("%49s", username);

    printf("Password: ");
    scanf("%49s", password);

    while (fscanf(file, "%49[^;];%49[^;];%49[^\n]\n",
                  fileUsername,
                  filePassword,
                  role) == 3)
    {
        if (strcmp(username, fileUsername) == 0 &&
            strcmp(password, filePassword) == 0)
        {
            loginSuccess = 1;

            printf("\nLogin Successful!\n");
            printf("Welcome %s\n", role);
            strcpy(currentRole, role);

            fclose(file);
            return 1;
        }
    }

    fclose(file);

    if (!loginSuccess)
    {
        printf("\nInvalid username or password!\n");
    }

    return 0;
}