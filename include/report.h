#ifndef REPORT_H
#define REPORT_H

typedef struct
{
    int id;

    char date[20];
    char time[10];

    char disasterType[50];
    char city[50];
    char district[50];

    int severity;

    char description[200];

    char reporter[50];

    char status[30];

} Report;

#endif