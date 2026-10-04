# MFMS

## Shared design

### Rules
- One array of structs per module, with a MAX_ constant and a count variable.
- Use the helpers in utils.h for ALL user input.
- Only edit your own module's files. Work on your own branch.
- Compile with: gcc -std=c99 -Wall -Wextra *.c -o mfms

### Function names
- employeeMenu(), budgetMenu(), supplierMenu(), assetMenu(), reportsMenu()
- addXxx(), displayXxx(), searchXxx() in each module

### Structs
- Employee: id, name, department, basicSalary, housingAllowance, transportAllowance, grossSalary
- Budget: department, allocated, spent, remaining
- Supplier: id, name, email, phone, town
- Asset: id, name, type, purchaseValue, department, condition

### Roles
- Immanuel Petrus: main.c, utils, Git coordination
- Employees: 
- Budget: 
- Suppliers: 
- Assets: 
- Reports: 
- Testing/docs: see TESTING.md and tests/ (Budget unit test + manual test plan)