#include <stdio.h>
#include <string.h>

#include "../budget.c"

static int testsRun = 0;
static int testsFailed = 0;

static void checkFloat(const char *name, float actual, float expected)
{
    const float eps = 0.001f;
    float diff = actual - expected;
    if (diff < 0) diff = -diff;

    testsRun++;
    if (diff <= eps) {
        printf("  PASS: %s (got %.2f)\n", name, actual);
    } else {
        testsFailed++;
        printf("  FAIL: %s (expected %.2f, got %.2f)\n", name, expected, actual);
    }
}

static Budget makeBudget(const char *dept, float allocated, float expenditure)
{
    Budget b;
    strncpy(b.department, dept, sizeof(b.department) - 1);
    b.department[sizeof(b.department) - 1] = '\0';
    b.allocated = allocated;
    b.expenditure = expenditure;
    return b;
}

static void testCalculateRemaining(void)
{
    printf("calculateRemaining:\n");

    checkFloat("within budget 1000-400", calculateRemaining(makeBudget("Roads", 1000.0f, 400.0f)), 600.0f);

    checkFloat("exceeded 1000-1200", calculateRemaining(makeBudget("Water", 1000.0f, 1200.0f)), -200.0f);

    checkFloat("exact 500-500", calculateRemaining(makeBudget("Parks", 500.0f, 500.0f)), 0.0f);

    checkFloat("no spend 750-0", calculateRemaining(makeBudget("Admin", 750.0f, 0.0f)), 750.0f);
}

static void smokeTestDisplayFunctions(void)
{
    printf("display/report smoke tests (visual output follows):\n");

    Budget budgets[3];
    budgets[0] = makeBudget("Roads", 1000.0f, 400.0f);
    budgets[1] = makeBudget("Water", 1000.0f, 1200.0f);
    budgets[2] = makeBudget("Parks", 500.0f, 500.0f);

    displayBudgets(budgets, 0);

    displayBudgets(budgets, 3);

    findExceededBudgets(budgets, 3);

    Budget within[1];
    within[0] = makeBudget("Admin", 2000.0f, 100.0f);
    findExceededBudgets(within, 1);

    testsRun++;
    printf("  PASS: display/report functions executed without crashing\n");
}

int main(void)
{
    printf("===== BUDGET MODULE UNIT TESTS =====\n");

    testCalculateRemaining();
    smokeTestDisplayFunctions();

    printf("\n------------------------------------\n");
    printf("Tests run: %d, failed: %d\n", testsRun, testsFailed);

    if (testsFailed == 0) {
        printf("ALL BUDGET TESTS PASSED\n");
        return 0;
    }

    printf("SOME BUDGET TESTS FAILED\n");
    return 1;
}
