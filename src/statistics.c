#include <stdio.h>
#include <string.h>
#include "../include/statistics.h"

void showStatistics()
{
    FILE *file;
    char line[256];
    char city[50];

    int totalReports = 0;

    int earthquake = 0;
    int flood = 0;
    int fire = 0;
    int other = 0;

    int totalSeverity = 0;
    int severity = 0;

    int malatya = 0;
    int kayseri = 0;
    int istanbul = 0;
    int ankara = 0;
    int otherCity = 0;

    file = fopen("reports.txt", "r");

    if (file == NULL)
    {
        printf("\nNo reports found.\n");
        return;
    }

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, "Report ID"))
        {
            totalReports++;
        }

        if (strstr(line, "Disaster Type"))
        {
            if (strstr(line, "Earthquake"))
                earthquake++;
            else if (strstr(line, "Flood"))
                flood++;
            else if (strstr(line, "Fire"))
                fire++;
            else
                other++;
        }

        if (strstr(line, "City"))
        {
            sscanf(line, "City           : %49[^\n]", city);

            if (strcmp(city, "Malatya") == 0)
                malatya++;
            else if (strcmp(city, "Kayseri") == 0)
                kayseri++;
            else if (strcmp(city, "Istanbul") == 0)
                istanbul++;
            else if (strcmp(city, "Ankara") == 0)
                ankara++;
            else
                otherCity++;
        }

        if (strstr(line, "Severity"))
        {
            sscanf(line, "Severity       : %d", &severity);
            totalSeverity += severity;
        }
    }

    fclose(file);

    char mostCity[30] = "Other";
    int maxCity = otherCity;

    if (malatya > maxCity)
    {
        maxCity = malatya;
        strcpy(mostCity, "Malatya");
    }

    if (kayseri > maxCity)
    {
        maxCity = kayseri;
        strcpy(mostCity, "Kayseri");
    }

    if (istanbul > maxCity)
    {
        maxCity = istanbul;
        strcpy(mostCity, "Istanbul");
    }

    if (ankara > maxCity)
    {
        maxCity = ankara;
        strcpy(mostCity, "Ankara");
    }

    printf("\n=====================================\n");
    printf("         ARES STATISTICS\n");
    printf("=====================================\n\n");

    printf("Total Reports      : %d\n\n", totalReports);

    printf("Earthquake         : %d\n", earthquake);
    printf("Flood              : %d\n", flood);
    printf("Fire               : %d\n", fire);
    printf("Other              : %d\n\n", other);

    printf("----------- City Statistics -----------\n");

    printf("Malatya            : %d\n", malatya);
    printf("Kayseri            : %d\n", kayseri);
    printf("Istanbul           : %d\n", istanbul);
    printf("Ankara             : %d\n", ankara);
    printf("Other              : %d\n\n", otherCity);

    printf("Most Reported City : %s\n", mostCity);

    if (totalReports > 0)
    {
        printf("Average Severity   : %.2f / 10\n",
               (float)totalSeverity / totalReports);
    }

    printf("\n=====================================\n");
}