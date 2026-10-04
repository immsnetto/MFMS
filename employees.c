#include <stdio.h>
#include <string.h>
#include "employees.h"

void addEmployee(Employee employees[], int *count)
{
    if (*count >= MAX_EMPLOYEES)
    {
        printf("\nEmployee limit reached.\n");
        return;
    }

    printf("\n--- Add Employee ---\n");

    printf("Enter employee ID: ");
    scanf("%d", &employees[*count].id);
    while (employees[*count].id <= 0)
    {
        printf("ID must be positive. Enter again: ");
        scanf("%d", &employees[*count].id);
    }

    getchar();

    printf("Enter employee name: ");
    fgets(employees[*count].name, 50, stdin);
    employees[*count].name[strcspn(employees[*count].name, "\n")] = '\0';

    while (strlen(employees[*count].name) == 0)
    {
        printf("Name cannot be empty. Enter again: ");
        fgets(employees[*count].name, 50, stdin);
        employees[*count].name[strcspn(employees[*count].name, "\n")] = '\0';
    }

    printf("Enter department: ");
    fgets(employees[*count].department, 50, stdin);
    employees[*count].department[strcspn(employees[*count].department, "\n")] = '\0';

    printf("Enter basic salary: ");
    scanf("%f", &employees[*count].basicSalary);
    while (employees[*count].basicSalary < 0)
    {
        printf("Salary cannot be negative. Enter again: ");
        scanf("%f", &employees[*count].basicSalary);
    }

    printf("Enter housing allowance: ");
    scanf("%f", &employees[*count].housingAllowance);
    while (employees[*count].housingAllowance < 0)
    {
        printf("Allowance cannot be negative. Enter again: ");
        scanf("%f", &employees[*count].housingAllowance);
    }

    printf("Enter transport allowance: ");
    scanf("%f", &employees[*count].transportAllowance);
    while (employees[*count].transportAllowance < 0)
    {
        printf("Allowance cannot be negative. Enter again: ");
        scanf("%f", &employees[*count].transportAllowance);
    }

    (*count)++;
    printf("Employee added successfully.\n");
}

void displayEmployees(Employee employees[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo employees registered.\n");
        return;
    }

    printf("\n--- Employee List ---\n");

    for (i = 0; i < count; i++)
    {
        printf("\nEmployee ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: N$%.2f\n", employees[i].housingAllowance);
        printf("Transport Allowance: N$%.2f\n", employees[i].transportAllowance);
        printf("Total Salary: N$%.2f\n", calculateSalary(employees[i]));
    }
}

void searchEmployee(Employee employees[], int count)
{
    int id, i, found = 0;

    if (count == 0)
    {
        printf("\nNo employees registered.\n");
        return;
    }

    printf("\n--- Search Employee ---\n");
    printf("Enter employee ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (employees[i].id == id)
        {
            printf("\nEmployee found!\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Department: %s\n", employees[i].department);
            printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
            printf("Housing Allowance: N$%.2f\n", employees[i].housingAllowance);
            printf("Transport Allowance: N$%.2f\n", employees[i].transportAllowance);
            printf("Total Salary: N$%.2f\n", calculateSalary(employees[i]));
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Employee not found.\n");
}

float calculateSalary(Employee employee)
{
    return employee.basicSalary
         + employee.housingAllowance
         + employee.transportAllowance;
}
