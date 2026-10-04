#include <stdio.h>
#include <string.h>
#include "assets.h"

static void readAssetString(char text[], int size, const char *prompt)
{
    do
    {
        printf("%s", prompt);
        fgets(text, size, stdin);
        text[strcspn(text, "\n")] = '\0';

        if (strlen(text) == 0)
            printf("Input cannot be empty.\n");

    } while (strlen(text) == 0);
}

void addAsset(Asset assets[], int *count)
{
    if (*count >= MAX_ASSETS)
    {
        printf("\nAsset limit reached.\n");
        return;
    }

    printf("\n--- Add Asset ---\n");

    printf("Enter asset ID: ");
    scanf("%d", &assets[*count].id);
    while (assets[*count].id <= 0)
    {
        printf("ID must be positive. Enter again: ");
        scanf("%d", &assets[*count].id);
    }

    getchar();

    readAssetString(assets[*count].name, 50, "Enter asset name: ");
    readAssetString(assets[*count].type, 50, "Enter asset type: ");

    printf("Enter purchase value: N$");
    scanf("%f", &assets[*count].purchaseValue);
    while (assets[*count].purchaseValue < 0)
    {
        printf("Purchase value cannot be negative. Enter again: N$");
        scanf("%f", &assets[*count].purchaseValue);
    }

    getchar();

    readAssetString(assets[*count].department, 50, "Enter department: ");
    readAssetString(assets[*count].condition, 30, "Enter condition: ");

    (*count)++;
    printf("Asset added successfully.\n");
}

void displayAssets(Asset assets[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo assets registered.\n");
        return;
    }

    printf("\n--- Asset Register ---\n");

    for (i = 0; i < count; i++)
    {
        printf("\nAsset ID: %d\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Purchase Value: N$%.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}

void searchAsset(Asset assets[], int count)
{
    int id, i, found = 0;

    if (count == 0)
    {
        printf("\nNo assets registered.\n");
        return;
    }

    printf("\n--- Search Asset ---\n");
    printf("Enter asset ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (assets[i].id == id)
        {
            printf("\nAsset found!\n");
            printf("ID: %d\n", assets[i].id);
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Purchase Value: N$%.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Asset not found.\n");
}
