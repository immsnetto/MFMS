#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 50

typedef struct
{
    char department[50];
    float allocated;
    float expenditure;
} Budget;

void addBudget(Budget budgets[], int *count);
void displayBudgets(Budget budgets[], int count);
float calculateRemaining(Budget budget);
void findExceededBudgets(Budget budgets[], int count);

#endif
