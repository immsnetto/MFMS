#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

typedef struct
{
    int id;
    char name[50];
    char email[80];
    char telephone[30];
    char town[50];
} Supplier;

void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(Supplier suppliers[], int count);
void searchSupplier(Supplier suppliers[], int count);

#endif
