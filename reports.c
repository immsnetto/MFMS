/* 
 * Module: Reports (Student 5)
 * Purpose: Implementation of reporting routines across modules and file exports
 */
#include <stdio.h>
#include "reports.h"

void employeeReport(Employee employees[], int count)
{
    int i;
    double total = 0.0;
    double highest = 0.0;
    double lowest = 0.0;

    if (count == 0)
    {
        printf("\nNo employees available for report.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        double salary = calculateSalary(employees[i]);
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
    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;

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
    printf("Remaining Budget: N$%.2f\n", totalAllocated - totalExpenditure);
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
    
    /* Ask user if they want to export to a file (Week 10 File Handling) */
    printf("\nWould you like to export this summary to a text file? (1=Yes, 0=No): ");
    int choice;
    if (scanf("%d", &choice) == 1 && choice == 1)
    {
        exportReportsToFile(employees, employeeCount, budgets, budgetCount);
    }
}

/* Exports the calculated summaries to a text file */
void exportReportsToFile(Employee employees[], int employeeCount,
                         Budget budgets[], int budgetCount)
{
    FILE *fp = fopen("reports_export.txt", "w");
    if (fp == NULL)
    {
        perror("Error opening reports_export.txt for writing");
        return;
    }

    fprintf(fp, "========================================\n");
    fprintf(fp, " MFMS CONSOLIDATED SYSTEM REPORT\n");
    fprintf(fp, "========================================\n\n");

    /* Employee Data Export */
    fprintf(fp, "--- EMPLOYEE SUMMARY ---\n");
    if (employeeCount == 0) {
        fprintf(fp, "No employees registered.\n");
    } else {
        double totalSal = 0.0;
        for (int i = 0; i < employeeCount; i++) {
            totalSal += calculateSalary(employees[i]);
        }
        fprintf(fp, "Total Employees: %d\n", employeeCount);
        fprintf(fp, "Average Salary: N$%.2f\n", totalSal / employeeCount);
    }

    /* Budget Data Export */
    fprintf(fp, "\n--- BUDGET SUMMARY ---\n");
    if (budgetCount == 0) {
        fprintf(fp, "No budgets registered.\n");
    } else {
        double totalAlloc = 0.0, totalExp = 0.0;
        for (int i = 0; i < budgetCount; i++) {
            totalAlloc += budgets[i].allocated;
            totalExp += budgets[i].expenditure;
        }
        fprintf(fp, "Total Allocated: N$%.2f\n", totalAlloc);
        fprintf(fp, "Total Expenditure: N$%.2f\n", totalExp);
        fprintf(fp, "Net Remaining: N$%.2f\n", totalAlloc - totalExp);
    }

    fclose(fp);
    printf("\nReport successfully exported to 'reports_export.txt'\n");
}