#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

void displayMainMenu(void);
void employeeMenu(Employee employees[], int *count);
void budgetMenu(Budget budgets[], int *count);
void supplierMenu(Supplier suppliers[], int *count);
void assetMenu(Asset assets[], int *count);
void reportsMenu(Employee employees[], int employeeCount,
                 Budget budgets[], int budgetCount,
                 Supplier suppliers[], int supplierCount,
                 Asset assets[], int assetCount);

int main(void)
{
    Employee employees[MAX_EMPLOYEES];
    Budget budgets[MAX_BUDGETS];
    Supplier suppliers[MAX_SUPPLIERS];
    Asset assets[MAX_ASSETS];

    int employeeCount = 0;
    int budgetCount = 0;
    int supplierCount = 0;
    int assetCount = 0;
    int choice;

    do
    {
        displayMainMenu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                employeeMenu(employees, &employeeCount);
                break;

            case 2:
                budgetMenu(budgets, &budgetCount);
                break;

            case 3:
                supplierMenu(suppliers, &supplierCount);
                break;

            case 4:
                assetMenu(assets, &assetCount);
                break;

            case 5:
                reportsMenu(employees, employeeCount,
                             budgets, budgetCount,
                             suppliers, supplierCount,
                             assets, assetCount);
                break;

            case 6:
                printf("\nThank you for using the Municipal Financial Management System.\n");
                break;

            default:
                printf("\nInvalid menu choice. Please select 1-6.\n");
        }

    } while (choice != 6);

    return 0;
}

void displayMainMenu(void)
{
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("========================================\n");
}

void employeeMenu(Employee employees[], int *count)
{
    int choice;

    do
    {
        printf("\n--- Employee Management ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                addEmployee(employees, count);
                break;
            case 2:
                displayEmployees(employees, *count);
                break;
            case 3:
                searchEmployee(employees, *count);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
}

void budgetMenu(Budget budgets[], int *count)
{
    int choice;

    do
    {
        printf("\n--- Budget Management ---\n");
        printf("1. Add Department Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Find Departments Exceeding Budget\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                addBudget(budgets, count);
                break;
            case 2:
                displayBudgets(budgets, *count);
                break;
            case 3:
                findExceededBudgets(budgets, *count);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
}

void supplierMenu(Supplier suppliers[], int *count)
{
    int choice;

    do
    {
        printf("\n--- Supplier Management ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                addSupplier(suppliers, count);
                break;
            case 2:
                displaySuppliers(suppliers, *count);
                break;
            case 3:
                searchSupplier(suppliers, *count);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
}

void assetMenu(Asset assets[], int *count)
{
    int choice;

    do
    {
        printf("\n--- Asset Management ---\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                addAsset(assets, count);
                break;
            case 2:
                displayAssets(assets, *count);
                break;
            case 3:
                searchAsset(assets, *count);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
}

void reportsMenu(Employee employees[], int employeeCount,
                 Budget budgets[], int budgetCount,
                 Supplier suppliers[], int supplierCount,
                 Asset assets[], int assetCount)
{
    int choice;

    do
    {
        printf("\n--- Reports ---\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. All Reports\n");
        printf("6. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                employeeReport(employees, employeeCount);
                break;
            case 2:
                budgetReport(budgets, budgetCount);
                break;
            case 3:
                supplierReport(suppliers, supplierCount);
                break;
            case 4:
                assetReport(assets, assetCount);
                break;
            case 5:
                displayAllReports(employees, employeeCount,
                                   budgets, budgetCount,
                                   suppliers, supplierCount,
                                   assets, assetCount);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);
}
