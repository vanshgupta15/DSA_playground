/*create a student record using an array 
a) Perform insertion and deletion operation
b) Search the record using key roll number
*/


#include <stdio.h>
#include <string.h>

#define MAX 100

// Define structure
struct Student {
    char name[50];
    int rollNumber;
    float cgpa;
};

// Function prototypes
void insertStudent(struct Student students[], int *count);
void deleteStudent(struct Student students[], int *count, int roll);
void searchStudent(struct Student students[], int count, int roll);
void printStudents(struct Student students[], int count);

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice, roll;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student by Roll Number\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Print All Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent(students, &count);
                break;
            case 2:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteStudent(students, &count, roll);
                break;
            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                searchStudent(students, count, roll);
                break;
            case 4:
                printStudents(students, count);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Function to insert a student
void insertStudent(struct Student students[], int *count) {
    if (*count >= MAX) {
        printf("Cannot insert, array is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", students[*count].name);

    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);

    printf("Enter CGPA: ");
    scanf("%f", &students[*count].cgpa);

    (*count)++;
    printf("Student inserted successfully.\n");
}

// Function to delete a student by roll number
void deleteStudent(struct Student students[], int *count, int roll) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == roll) {
            found = 1;
            // Shift the rest
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("Student deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", roll);
    }
}

// Function to search student by roll number
void searchStudent(struct Student students[], int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == roll) {
            printf("Student found:\n");
            printf("Name: %s, Roll: %d, CGPA: %.2f\n",
            students[i].name, students[i].rollNumber, students[i].cgpa);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", roll);
}

// Function to print all students
void printStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Roll: %d, CGPA: %.2f\n",
        students[i].name, students[i].rollNumber, students[i].cgpa);
    }
}
