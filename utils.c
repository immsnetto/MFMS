
#include <stdio.h>
#include "utils.h"

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* keep reading and throwing away characters */
    }
}

int readIntInRange(const char *prompt, int min, int max)
{
    int value;

    while (1) {
        printf("%s", prompt);

        if (scanf("%d", &value) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (value < min || value > max) {
            printf("Please enter a number between %d and %d.\n", min, max);
            continue;
        }

        return value;
    }
}

double readPositiveDouble(const char *prompt)
{
    double value;

    while (1) {
        printf("%s", prompt);

        if (scanf("%lf", &value) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        if (value <= 0) {
            printf("Value must be greater than zero.\n");
            continue;
        }

        return value;
    }
}