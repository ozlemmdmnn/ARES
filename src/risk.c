#include <stdio.h>
#include "../include/risk.h"

void riskAnalysis()
{
    int level;

    printf("\n========== RISK ANALYSIS ==========\n");
    printf("Enter risk level (1-10): ");
    scanf("%d", &level);

    if (level >= 8)
    {
        printf("\nHIGH RISK!\n");
        printf("Recommendation: Send emergency teams immediately.\n");
    }
    else if (level >= 5)
    {
        printf("\nMEDIUM RISK!\n");
        printf("Recommendation: Monitor the area.\n");
    }
    else
    {
        printf("\nLOW RISK!\n");
        printf("Recommendation: No immediate action required.\n");
    }
}