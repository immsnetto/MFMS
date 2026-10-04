# MFMS Testing Documentation

This document describes how the Municipal Financial Management System (MFMS) is
tested, what is currently covered, and the manual test cases for each module.

## 1. Build & environment

The project is C99 and is intended to build with:

```
gcc -std=c99 -Wall -Wextra *.c -o mfms
```

> NOTE: A C compiler (e.g. `gcc` via MinGW-w64) must be installed and on the
> `PATH`. On the current development machine no compiler was detected, so the
> commands below must be run in an environment that has one installed.

## 2. Current implementation status

Testing can only cover code that exists. As of this document:

| Module    | Status            | Testable logic                                             |
|-----------|-------------------|------------------------------------------------------------|
| Budget    | Implemented       | `addBudget`, `displayBudgets`, `calculateRemaining`, `findExceededBudgets` |
| Employees | Stub ("coming soon") | None yet                                                |
| Suppliers | Stub ("coming soon") | None yet                                                |
| Assets    | Stub ("coming soon") | None yet                                                |
| Reports   | Partially written | Depends on types/functions not yet implemented (see 2.1)   |

### 2.1 Known blocking issue (Reports module)

`reports.c` / `reports.h` reference types and functions that do not yet exist:

- `Employee`, `Supplier`, `Asset` structs
- `calculateSalary()`, `displaySuppliers()`, `displayAssets()`

Because of this, a full-project build (`gcc *.c`) will currently **fail to
compile**. The automated unit test (see section 4) deliberately compiles only
`budget.c` so the Budget logic can be tested in isolation until the other
modules are finished.

## 3. Test levels

1. **Unit tests** – automated checks of pure logic functions (currently Budget).
2. **Manual / integration tests** – running the built program and exercising
   each menu by hand against the test cases in section 5.

## 4. Automated unit tests

Automated tests live in the `tests/` folder. They are standalone C programs
that include a module's source directly and assert expected results.

Run the Budget unit test (from the project root):

```
gcc -std=c99 -Wall -Wextra tests/test_budget.c -o test_budget
./test_budget
```

Expected result: all assertions pass and the program prints
`ALL BUDGET TESTS PASSED` with exit code 0. Any failure prints the failing
case and exits non-zero.

See `tests/README.md` for details.

## 5. Manual test cases

### 5.1 Main menu (main.c + utils)

| # | Test | Steps | Expected |
|---|------|-------|----------|
| M1 | Valid choice routes correctly | Enter `2` at main menu | Budget menu/logic runs |
| M2 | Out-of-range rejected | Enter `0` or `7` | "Please enter a number between 1 and 6." reprompt |
| M3 | Non-numeric rejected | Enter `abc` | "Invalid input. Please enter a number." reprompt |
| M4 | Exit | Enter `6` | Prints "Goodbye." and program ends |

### 5.2 utils helpers

| # | Function | Input | Expected |
|---|----------|-------|----------|
| U1 | `readIntInRange` | below min / above max | reprompt until in range |
| U2 | `readIntInRange` | letters | "Invalid input" reprompt |
| U3 | `readPositiveDouble` | `0` or negative | "Value must be greater than zero." reprompt |
| U4 | `readPositiveDouble` | letters | "Invalid input" reprompt |
| U5 | `readNonEmptyString` | empty (just Enter) | "Input cannot be empty." reprompt |
| U6 | `readNonEmptyString` | long string > size | truncated to buffer, buffer cleared, no overflow |

### 5.3 Budget module

| # | Test | Steps | Expected |
|---|------|-------|----------|
| B1 | Add valid budget | Add dept "Roads", allocated 1000, expenditure 400 | "Budget added successfully." |
| B2 | Empty department rejected | Press Enter for department | "Department cannot be empty." reprompt |
| B3 | Negative allocated rejected | Enter `-5` for allocated | "Budget cannot be negative." reprompt |
| B4 | Negative expenditure rejected | Enter `-5` for expenditure | "Expenditure cannot be negative." reprompt |
| B5 | Remaining within budget | allocated 1000, expenditure 400 | Remaining N$600.00, "WITHIN BUDGET" |
| B6 | Exceeded budget | allocated 1000, expenditure 1200 | "Amount Over Budget: N$200.00", "EXCEEDED BUDGET" |
| B7 | Display with no records | display before adding | "No budgets registered." |
| B8 | Find exceeded (none) | all within budget | "No departments have exceeded their budgets." |
| B9 | Find exceeded (some) | one dept over | lists dept and over-amount |
| B10 | Capacity limit | add until MAX_BUDGETS (50) then one more | "Budget limit reached." |

### 5.4 Employees / Suppliers / Assets (stubs)

| # | Test | Expected |
|---|------|----------|
| S1 | Open Employee menu | Prints "Employee Management - coming soon." |
| S2 | Open Supplier menu | Prints "Supplier Management - coming soon." |
| S3 | Open Asset menu | Prints "Asset Management - coming soon." |

These become full test suites once the modules are implemented.

### 5.5 Reports

Blocked until the Employee/Supplier/Asset structs and helper functions exist
(see 2.1). Once implemented, test:

- Employee report totals/average/highest/lowest with 0 and N employees.
- Budget report totals and exceeded count.
- Export to `reports_export.txt` produces a readable file matching on-screen data.

## 6. Regression checklist (run before each merge)

- [ ] `gcc -std=c99 -Wall -Wextra tests/test_budget.c -o test_budget` builds with no warnings
- [ ] `./test_budget` prints `ALL BUDGET TESTS PASSED`
- [ ] Full build `gcc -std=c99 -Wall -Wextra *.c -o mfms` succeeds (once Reports is unblocked)
- [ ] Manual cases M1–M4 pass
- [ ] Budget cases B1–B10 pass
