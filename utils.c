
#include <stdio.h>
#include "utils.h"

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* keep reading and throwing away characters */
    }
}