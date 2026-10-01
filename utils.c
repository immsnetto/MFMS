
#include <stdio.h>
#include <string.h>
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

void readNonEmptyString(const char *prompt, char *dest, int size)
{
    size_t len;

    while (1) {
        printf("%s", prompt);

        if (fgets(dest, size, stdin) == NULL) {
            printf("Input error.\n");
            dest[0] = '\0';
            return;
        }

        len = strlen(dest);

        if (len > 0 && dest[len - 1] == '\n') {
            dest[len - 1] = '\0';
        } else {
            clearInputBuffer();
        }

        if (strlen(dest) == 0) {
            printf("Input cannot be empty. Please try again.\n");
            continue;
        }

        return;
    }
}