#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 100
#define STR_LEN 50

 {
    int id;
    char name[STR_LEN];
    char email[STR_LEN];
    char phone[STR_LEN];
    char location[STR_LEN];
} Supplier;


void clearBuffer(void);
void addSupplier(Supplier suppliers[], int *supplierCount);
void displaySingleSupplier(const Supplier *sup);
void displaySuppliers(const Supplier suppliers[], int supplierCount);
void searchSupplier(const Supplier suppliers[], int supplierCount);
void supplierMenu(Supplier suppliers[], int *supplierCount);


int main(void) {
    Supplier suppliers[MAX_SUPPLIERS];
    int supplierCount = 0;
    int choice;

    do {
        printf("\n=========================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM   \n");
        printf("=========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("[Invalid Choice] Please enter a valid number.\n");
            clearBuffer();
            continue;
        }

        switch (choice) {
            case 3:
                supplierMenu(suppliers, &supplierCount);
                break;
            case 1:
            case 2:
            case 4:
            case 5:
                printf("\n[Info] This module is handled in another section.\n");
                break;
            case 6:
                printf("\nExiting system. Goodbye!\n");
                break;
            default:
                printf("\n[Invalid Choice] Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

 {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

 {
    if (*supplierCount >= MAX_SUPPLIERS) {
        printf("\n[Error] Maximum supplier capacity reached (%d)!\n", MAX_SUPPLIERS);
        return;
    }

    Supplier newSup;

  {
        printf("\nEnter Supplier ID (positive integer): ");
        if (scanf("%d", &newSup.id) != 1 || newSup.id <= 0) {
            printf("[Invalid Input] ID must be a positive integer.\n");
            clearBuffer();
            newSup.id = -1;
        } else {
            
            for (int i = 0; i < *supplierCount; i++) {
                if (suppliers[i].id == newSup.id) {
                    printf("[Invalid Input] Supplier ID %d already exists!\n", newSup.id);
                    newSup.id = -1;
                    break;
                }
            }
        }
    } while (newSup.id <= 0);

    clearBuffer();

   {
        printf("Enter Supplier Name: ");
        if (fgets(newSup.name, STR_LEN, stdin) != NULL) {
            newSup.name[strcspn(newSup.name, "\n")] = '\0';
        }
        if (strlen(newSup.name) == 0) {
            printf("[Invalid Input] Name cannot be empty.\n");
        }
    } while (strlen(newSup.name) == 0);

 {
        printf("Enter Email Address: ");
        if (fgets(newSup.email, STR_LEN, stdin) != NULL) {
            newSup.email[strcspn(newSup.email, "\n")] = '\0';
        }
        if (strlen(newSup.email) == 0) {
            printf("[Invalid Input] Email cannot be empty.\n");
        }
    } while (strlen(newSup.email) == 0);

    // Validate Telephone Number
    do {
        printf("Enter Telephone Number: ");
        if (fgets(newSup.phone, STR_LEN, stdin) != NULL) {
            newSup.phone[strcspn(newSup.phone, "\n")] = '\0';
        }
        if (strlen(newSup.phone) == 0) {
            printf("[Invalid Input] Telephone number cannot be empty.\n");
        }
    } while (strlen(newSup.phone) == 0);

  {
        printf("Enter Town/Location: ");
        if (fgets(newSup.location, STR_LEN, stdin) != NULL) {
            newSup.location[strcspn(newSup.location, "\n")] = '\0';
        }
        if (strlen(newSup.location) == 0) {
            printf("[Invalid Input] Location cannot be empty.\n");
        }
    } while (strlen(newSup.location) == 0);

   
    suppliers[*supplierCount] = newSup;
    (*supplierCount)++;

    printf("\n>>> Supplier added successfully!\n");
}

{
    printf("%-8d %-22s %-25s %-15s %-15s\n",
           sup->id,
           sup->name,
           sup->email,
           sup->phone,
           sup->location);
}
 {
    if (supplierCount == 0) {
        printf("\nNo suppliers found in the system.\n");
        return;
    }

    printf("\n=================================== SUPPLIER RECORDS ===================================\n");
    printf("%-8s %-22s %-25s %-15s %-15s\n",
           "ID", "Supplier Name", "Email", "Telephone", "Town/Location");
    printf("----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < supplierCount; i++) {
        displaySingleSupplier(&suppliers[i]);
    }
    printf("========================================================================================\n");
}
{
    if (supplierCount == 0) {
        printf("\nNo suppliers available to search.\n");
        return;
    }

    int choice;
    printf("\n--- Search / Compare Supplier Information ---\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("3. Search/Filter by Town/Location\n");
    printf("Enter choice: ");

    if (scanf("%d", &choice) != 1) {
        printf("[Invalid Input] Please enter a valid choice.\n");
        clearBuffer();
        return;
    }

    int found = 0;

    if (choice == 1) {
        int searchId;
        printf("Enter Supplier ID: ");
        if (scanf("%d", &searchId) != 1) {
            printf("[Invalid Input] Invalid ID format.\n");
            clearBuffer();
            return;
        }

        for (int i = 0; i < supplierCount; i++) {
            if (suppliers[i].id == searchId) {
                printf("\n--- Supplier Found ---\n");
                printf("%-8s %-22s %-25s %-15s %-15s\n",
                       "ID", "Supplier Name", "Email", "Telephone", "Town/Location");
                displaySingleSupplier(&suppliers[i]);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        char searchName[STR_LEN];
        clearBuffer();
        printf("Enter Supplier Name: ");
        if (fgets(searchName, STR_LEN, stdin) != NULL) {
            searchName[strcspn(searchName, "\n")] = '\0';
        }

        for (int i = 0; i < supplierCount; i++) {
            if (strcmp(suppliers[i].name, searchName) == 0) {
                if (!found) {
                    printf("\n--- Supplier Found ---\n");
                    printf("%-8s %-22s %-25s %-15s %-15s\n",
                           "ID", "Supplier Name", "Email", "Telephone", "Town/Location");
                }
                displaySingleSupplier(&suppliers[i]);
                found = 1;
            }
        }
    } else if (choice == 3) {
        char searchLoc[STR_LEN];
        clearBuffer();
        printf("Enter Town/Location: ");
        if (fgets(searchLoc, STR_LEN, stdin) != NULL) {
            searchLoc[strcspn(searchLoc, "\n")] = '\0';
        }

        for (int i = 0; i < supplierCount; i++) {
            if (strcmp(suppliers[i].location, searchLoc) == 0) {
                if (!found) {
                    printf("\n--- Suppliers in %s ---\n", searchLoc);
                    printf("%-8s %-22s %-25s %-15s %-15s\n",
                           "ID", "Supplier Name", "Email", "Telephone", "Town/Location");
                }
                displaySingleSupplier(&suppliers[i]);
                found = 1;
            }
        }
    } else {
        printf("[Invalid Choice] Please select 1, 2, or 3.\n");
        return;
    }

    if (!found) {
        printf("\nNo record found matching the criteria.\n");
    }
}

{
    int choice;
    do {
        printf("\n===================================\n");
        printf("      SUPPLIER MANAGEMENT MENU     \n");
        printf("===================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search / Compare Suppliers\n");
        printf("4. Return to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("[Invalid Input] Please enter a valid choice.\n");
            clearBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                addSupplier(suppliers, supplierCount);
                break;
            case 2:
                displaySuppliers(suppliers, *supplierCount);
                break;
            case 3:
                searchSupplier(suppliers, *supplierCount);
                break;
            case 4:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("[Invalid Choice] Select an option between 1 and 4.\n");
        }
    } while (choice != 4);
}
