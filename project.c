#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "patients.txt"

// Structure for Patient
typedef struct {
    int id;
    char name[50];
    int age;
    char disease[50];
} Patient;

// Function to add a new patient
void addPatient() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Patient p;
    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Disease: ");
    scanf(" %[^\n]", p.disease);

    fprintf(file, "%d %s %d %s\n", p.id, p.name, p.age, p.disease);
    fclose(file);
    
    printf("Patient added successfully!\n");
}

// Function to display all patients
void displayPatients() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No records found!\n");
        return;
    }

    Patient p;
    printf("\n--- Patient List ---\n");
    while (fscanf(file, "%d %s %d %[^\n]", &p.id, p.name, &p.age, p.disease) != EOF) {
        printf("ID: %d, Name: %s, Age: %d, Disease: %s\n", p.id, p.name, p.age, p.disease);
    }

    fclose(file);
}

// Function to search for a patient by ID
void searchPatient() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No records found!\n");
        return;
    }

    int id, found = 0;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);

    Patient p;
    while (fscanf(file, "%d %s %d %[^\n]", &p.id, p.name, &p.age, p.disease) != EOF) {
        if (p.id == id) {
            printf("Patient Found!\nID: %d, Name: %s, Age: %d, Disease: %s\n", p.id, p.name, p.age, p.disease);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Patient not found!\n");
    }

    fclose(file);
}

// Function to delete a patient record
void deletePatient() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No records found!\n");
        return;
    }

    int id, found = 0;
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    FILE *tempFile = fopen("temp.txt", "w");
    Patient p;

    while (fscanf(file, "%d %s %d %[^\n]", &p.id, p.name, &p.age, p.disease) != EOF) {
        if (p.id == id) {
            found = 1;
            printf("Patient record deleted successfully!\n");
        } else {
            fprintf(tempFile, "%d %s %d %s\n", p.id, p.name, p.age, p.disease);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (!found) {
        printf("Patient not found!\n");
    }
}

// Main menu
void menu() {
    int choice;
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Search Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                deletePatient();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Main function
int main() {
    menu();
    return 0;
}

/*Hospital Management System
1. Add Patient
2. View Patients
3. Search Patient
4. Delete Patient
5. Exit
Enter your choice: 1
Enter Patient ID: 0013
Enter Name: Ahamed
Enter Age: 21
Enter Disease: pnemonia
Patient added successfully!

Hospital Management System
1. Add Patient
2. View Patients
3. Search Patient
4. Delete Patient
5. Exit
Enter your choice: 1
Enter Patient ID: 0013
Enter Name: ahamed
Enter Age: 21
Enter Disease: pneumonia
Patient added successfully!

Hospital Management System
1. Add Patient
2. View Patients
3. Search Patient
4. Delete Patient
5. Exit
Enter your choice: 2

--- Patient List ---
ID: 13, Name: Ahamed, Age: 21, Disease: pnemonia
ID: 13, Name: ahamed, Age: 21, Disease: pneumonia

Hospital Management System
1. Add Patient
2. View Patients
3. Search Patient
4. Delete Patient
5. Exit
Enter your choice: 3
Enter Patient ID to search: 0013
Patient Found!
ID: 13, Name: Ahamed, Age: 21, Disease: pnemonia

Hospital Management System
1. Add Patient
2. View Patients
3. Search Patient
4. Delete Patient
5. Exit
Enter your choice: 4
Enter Patient ID to delete: 0013
Patient record deleted successfully!
Patient record deleted successfully!

Hospital Management System
1. Add Patient
2. View Patients
3. Search Patient
4. Delete Patient
5. Exit
Enter your choice:*/
