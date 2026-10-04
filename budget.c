#include <stdio.h>
#include <string.h>
#include "budget.h"

void addBudget(Budget budgets[], int *count)
{
    if (*count >= MAX_BUDGETS)
    {
        printf("\nBudget limit reached.\n");
        return;
    }

    getchar();

    printf("\n--- Add Department Budget ---\n");
    printf("Enter department: ");
    fgets(budgets[*count].department, 50, stdin);
    budgets[*count].department[strcspn(budgets[*count].department, "\n")] = '\0';

    while (strlen(budgets[*count].department) == 0)
    {
        printf("Department cannot be empty. Enter again: ");
        fgets(budgets[*count].department, 50, stdin);
        budgets[*count].department[strcspn(budgets[*count].department, "\n")] = '\0';
    }

    printf("Enter allocated budget: N$");
    scanf("%f", &budgets[*count].allocated);
    while (budgets[*count].allocated < 0)
    {
        printf("Budget cannot be negative. Enter again: N$");
        scanf("%f", &budgets[*count].allocated);
    }

    printf("Enter expenditure: N$");
    scanf("%f", &budgets[*count].expenditure);
    while (budgets[*count].expenditure < 0)
    {
        printf("Expenditure cannot be negative. Enter again: N$");
        scanf("%f", &budgets[*count].expenditure);
    }

    (*count)++;
    printf("Budget added successfully.\n");
}

void displayBudgets(Budget budgets[], int count)
{
    int i;
    float remaining;

    if (count == 0)
    {
        printf("\nNo budgets registered.\n");
        return;
    }

    printf("\n--- Budget Report ---\n");

    for (i = 0; i < count; i++)
    {
        remaining = calculateRemaining(budgets[i]);

        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated Budget: N$%.2f\n", budgets[i].allocated);
        printf("Expenditure: N$%.2f\n", budgets[i].expenditure);

        if (remaining >= 0)
            printf("Remaining Budget: N$%.2f\nStatus: WITHIN BUDGET\n", remaining);
        else
            printf("Amount Over Budget: N$%.2f\nStatus: EXCEEDED BUDGET\n", -remaining);
    }
}

float calculateRemaining(Budget budget)
{
    return budget.allocated - budget.expenditure;
}

void findExceededBudgets(Budget budgets[], int count)
{
    int i, found = 0;

    printf("\n--- Departments Exceeding Budget ---\n");

    for (i = 0; i < count; i++)
    {
        if (budgets[i].expenditure > budgets[i].allocated)
        {
            printf("%s: Over by N$%.2f\n",
                   budgets[i].department,
                   budgets[i].expenditure - budgets[i].allocated);
            found = 1;
        }
    }

    if (!found)
        printf("No departments have exceeded their budgets.\n");
}
