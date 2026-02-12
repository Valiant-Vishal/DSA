/*
Step 1 : Hash Function: Get an index by calculating key % SIZE.

Step 2 : Insert (key, value): Hash the key to get an index. Create a new node. If the index is empty, place the node there. If not (collision), go to the end of the linked list at that index and add the node.

Step 3 : Search (key): Hash the key to get the index. Walk the linked list at that index until you find a node with a matching key. Return its value or -1 if not found.

Step 4 : Delete (key): Hash the key to get the index. Search the linked list for the key, linking the previous node to the next node when found, then free the deleted node.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define SIZE 10 
typedef struct Node {
    int key;
    int value;
    struct Node* next; 
} Node;

Node* hashTable[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int hashFunction(int key) {
    if (key < 0) {
        key = -key; 
    }
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode; 
    }
    printf("Inserted: Key=%d, Value=%d\n", key, value);
}

int search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value; 
        }
        temp = temp->next;
    }

    return -1;
}

void deleteKey(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key %d not found for deletion\n", key);
        return;
    }

    if (prev == NULL) {
        hashTable[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp); 
    printf("Deleted key: %d\n", key);
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("(%d,%d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeTable() {
    printf("Freeing all nodes...\n");
    for (int i = 0; i < SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
        hashTable[i] = NULL;
    }
}

int main() {
    initialize();
    int choice, key, value, result;

    printf("Hash Table Operations\n");
    printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            continue;
        }

        switch (choice) {
            case 1: 
                printf("Enter key and value to insert: ");
                if (scanf("%d %d", &key, &value) == 2) {
                    insert(key, value);
                } else {
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {}
                    printf("Invalid input for key/value.\n");
                }
                break;

            case 2: 
                printf("Enter key to search: ");
                if (scanf("%d", &key) == 1) {
                    result = search(key);
                    if (result != -1) {
                        printf("Found: Key=%d, Value=%d\n", key, result);
                    } else {
                        printf("Key %d not found\n", key);
                    }
                } else {
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {}
                    printf("Invalid input for key.\n");
                }
                break;

            case 3: 
                printf("Enter key to delete: ");
                if (scanf("%d", &key) == 1) {
                    deleteKey(key);
                } else {
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) {}
                    printf("Invalid input for key.\S\n");
                }
                break;

            case 4: 
                display();
                break;

            case 5: 
                freeTable(); 
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    return 0; 
}