
#ifndef UTILS_H
#define UTILS_H

void   clearInputBuffer(void);
int    readIntInRange(const char *prompt, int min, int max);
double readPositiveDouble(const char *prompt);
void   readNonEmptyString(const char *prompt, char *dest, int size);

#endif