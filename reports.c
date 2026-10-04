#include <stdio.h>
#include "reports.h"

void employeeReport(Employee employees[], int count)
{
    int i;
    float total = 0.0f;
    float highest = 0.0f;
    float lowest = 0.0f;

    if (count == 0)
    {
        printf("\nNo employees available for report.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        float salary = calculateSalary(employees[i]);
        total += salary;

        if (i == 0 || salary > highest)
            highest = salary;

        if (i == 0 || salary < lowest)
            lowest = salary;
    }

    printf("\n--- Employee Report ---\n");
    printf("Total Employees: %d\n", count);
    printf("Average Salary: N$%.2f\n", total / count);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);
}

void budgetReport(Budget budgets[], int count)
{
    int i, exceeded = 0;
    float totalAllocated = 0.0f;
    float totalExpenditure = 0.0f;

    if (count == 0)
    {
        printf("\nNo budgets available for report.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        totalAllocated += budgets[i].allocated;
        totalExpenditure += budgets[i].expenditure;

        if (budgets[i].expenditure > budgets[i].allocated)
            exceeded++;
    }

    printf("\n--- Budget Report ---\n");
    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Remaining Budget: N$%.2f\n",
           totalAllocated - totalExpenditure);
    printf("Departments Exceeding Budget: %d\n", exceeded);

    findExceededBudgets(budgets, count);
}

void supplierReport(Supplier suppliers[], int count)
{
    printf("\n--- Supplier Report ---\n");
    displaySuppliers(suppliers, count);
}

void assetReport(Asset assets[], int count)
{
    printf("\n--- Asset Report ---\n");
    displayAssets(assets, count);
}

void displayAllReports(Employee employees[], int employeeCount,
                       Budget budgets[], int budgetCount,
                       Supplier suppliers[], int supplierCount,
                       Asset assets[], int assetCount)
{
    employeeReport(employees, employeeCount);
    budgetReport(budgets, budgetCount);
    supplierReport(suppliers, supplierCount);
    assetReport(assets, assetCount);
}
