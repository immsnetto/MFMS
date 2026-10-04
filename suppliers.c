#include <stdio.h>
#include <string.h>
#include "suppliers.h"

static void readString(char text[], int size, const char *prompt)
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

void addSupplier(Supplier suppliers[], int *count)
{
    if (*count >= MAX_SUPPLIERS)
    {
        printf("\nSupplier limit reached.\n");
        return;
    }

    printf("\n--- Add Supplier ---\n");

    printf("Enter supplier ID: ");
    scanf("%d", &suppliers[*count].id);
    while (suppliers[*count].id <= 0)
    {
        printf("ID must be positive. Enter again: ");
        scanf("%d", &suppliers[*count].id);
    }

    getchar();

    readString(suppliers[*count].name, 50, "Enter supplier name: ");
    readString(suppliers[*count].email, 80, "Enter email: ");
    readString(suppliers[*count].telephone, 30, "Enter telephone: ");
    readString(suppliers[*count].town, 50, "Enter town/location: ");

    (*count)++;
    printf("Supplier added successfully.\n");
}

void displaySuppliers(Supplier suppliers[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo suppliers registered.\n");
        return;
    }

    printf("\n--- Supplier List ---\n");

    for (i = 0; i < count; i++)
    {
        printf("\nSupplier ID: %d\n", suppliers[i].id);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Telephone: %s\n", suppliers[i].telephone);
        printf("Town/Location: %s\n", suppliers[i].town);
    }
}

void searchSupplier(Supplier suppliers[], int count)
{
    int id, i, found = 0;

    if (count == 0)
    {
        printf("\nNo suppliers registered.\n");
        return;
    }

    printf("\n--- Search Supplier ---\n");
    printf("Enter supplier ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (suppliers[i].id == id)
        {
            printf("\nSupplier found!\n");
            printf("ID: %d\n", suppliers[i].id);
            printf("Name: %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].telephone);
            printf("Town/Location: %s\n", suppliers[i].town);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Supplier not found.\n");
}
