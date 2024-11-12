#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct node {
    int data;
    struct node* next;
};

// Initialize start to NULL
struct node* start = NULL;

// Function to insert a node at the end of the linked list
void insert_end() {
    struct node* new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &new_node->data);

    if (start == NULL) {
        new_node->next = NULL;
        start = new_node;
    } else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }
}

// Function to sort the linked list using Bubble Sort
void sortLinkedList() {
    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    // Check for empty list
    if (start == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to display the linked list
void displayList() {
    struct node* temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to drive the program
int main() {
    int choice;

    while (1) {
        printf("\n1. Insert an integer\n2. Sort the list\n3. Display the list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_end();
                break;
            case 2:
                sortLinkedList();
                printf("Linked list sorted successfully.\n");
                break;
            case 3:
                printf("Linked List: ");
                displayList();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
