#include <stdio.h>
#include <string.h>
#include "../include/login.h"

void login()
{
    char username[50];
    char password[50];

    printf("\n========== LOGIN ==========\n");

    printf("Username: ");
    scanf("%49s", username);

    printf("Password: ");
    scanf("%49s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0)
    {
        printf("\nLogin successful!\n");
    }
    else
    {
        printf("\nInvalid username or password!\n");
    }
}