/*
Step 1 :Insert at Beginning: Create a newnode, point its next to the current head, and then update head to be the newnode.

Step 2 :Insert at End: Create a newnode. If head is NULL, make it the head. Otherwise, traverse to the last node and set its next to the newnode.

Step 3 :Delete at End: If head is NULL, stop. If head->next is NULL, free the head and set it to NULL. Otherwise, traverse with prev and temp pointers to the end, set prev->next to NULL, and free temp.

Step 4 :Display: Start a temp pointer at head, print temp->data, and move temp to temp->next until temp is NULL.

Step 5 :Count: Initialize count = 0. Traverse the list with temp, incrementing count for each node, and print the final count.
*/

#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

// Global head pointer, initialized to NULL (empty list)
struct node *head = NULL;


struct node* createNode(int value) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

// --- Linked List Operations ---

void insertAtBeginning() {
    int value;
    printf("\nEnter data to insert at beginning: ");
    scanf("%d", &value);

    struct node *newnode = createNode(value);
    
    // Point the new node's next to the current head
    newnode->next = head;
    
    // Update the head to be the new node
    head = newnode;
    
    printf("Node inserted at beginning successfully.\n");
}


void insertAtEnd() {
    int value;
    printf("\nEnter data to insert at end: ");
    scanf("%d", &value);

    struct node *newnode = createNode(value);

    if (head == NULL) {
        // If the list is empty, the new node becomes the head
        head = newnode;
    } else {
        // Traverse to the last node
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Point the last node's next to the new node
        temp->next = newnode;
    }
    printf("Node inserted at end successfully.\n");
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    // Case 1: Only one node in the list
    if (head->next == NULL) {
        printf("Deleted node with data = %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    // Case 2: More than one node
    // Traverse to the last node (temp) and keep track of the
    // second-to-last node (prev).
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next; // This was the line with the typo
    }

    printf("Deleted node with data = %d\n", temp->data);
    
    // Unlink the last node
    prev->next = NULL; 
    
    free(temp);
}


void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void countNodes() {
    int count = 0;
    struct node *temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("\nTotal number of nodes = %d\n", count);
}

// --- Main Function (Menu Driver) ---

int main() {
    int choice;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete at End\n");
        printf("4. Display List\n");
        printf("5. Count Nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
        
            while (getchar() != '\n'); 
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                deleteAtEnd();
                break;
            case 4:
                display();
                break;
            case 5:
                countNodes();
                break;
            case 6:
                
                while (head != NULL) {
                    struct node *temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}