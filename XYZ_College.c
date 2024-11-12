#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct Student {
    int rollNumber;
    char name[50];
    int age;
    float percentage;
    struct Student* next;
};

// Function to create a new student node
struct Student* createStudent(int rollNumber) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNumber = rollNumber;

    printf("Enter name: ");
    scanf(" %[^\n]", newStudent->name);

    printf("Enter age: ");
    scanf("%d", &newStudent->age);

    printf("Enter percentage: ");
    scanf("%f", &newStudent->percentage);

    newStudent->next = NULL;
    return newStudent;
}

// Function to add a student at the end of the list
void addStudent(struct Student** head, int* rollCounter) {
    struct Student* newStudent = createStudent(*rollCounter);
    (*rollCounter)++;

    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// Function to display the list of students
void displayStudents(struct Student* head) {
    struct Student* temp = head;
    if (temp == NULL) {
        printf("No students to display.\n");
        return;
    }

    printf("Student Information:\n");
    while (temp != NULL) {
        printf("Roll Number: %d\n", temp->rollNumber);
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Percentage: %.2f\n", temp->percentage);
        printf("------------------------\n");
        temp = temp->next;
    }
}

int main() {
    struct Student* head = NULL;
    int rollCounter = 1;  // Start roll number from 1
    int choice;

    while (1) {
        printf("1. Add Student\n2. Display Students\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&head, &rollCounter);
                break;
            case 2:
                displayStudents(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
