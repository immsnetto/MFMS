#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void employeeReport(Employee employees[], int count);
void budgetReport(Budget budgets[], int count);
void supplierReport(Supplier suppliers[], int count);
void assetReport(Asset assets[], int count);
void displayAllReports(Employee employees[], int employeeCount,
                       Budget budgets[], int budgetCount,
                       Supplier suppliers[], int supplierCount,
                       Asset assets[], int assetCount);

#endif
