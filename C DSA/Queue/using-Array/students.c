#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

// Structure to hold student data
struct Student {
    int rollNo;
    char name[MAX_NAME_LEN];
    float mark;
};

// Structure to represent the circular queue
struct CircularQueue {
    struct Student* items; // Array to store queue elements
    int front;             // Front points to the first element
    int rear;              // Rear points to the last element
    int size;              // Current number of elements
    int capacity;          // Maximum capacity of the queue
};

// Function to create and initialize a queue
struct CircularQueue* createQueue(int capacity) {
    // Allocate memory for the queue structure itself
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    if (!queue) {
        printf("Memory allocation failed for queue!\n");
        return NULL;
    }
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    // Rear is initialized to the end for easier enqueue logic
    queue->rear = capacity - 1; 

    // Allocate memory for the student data array
    queue->items = (struct Student*)malloc(queue->capacity * sizeof(struct Student));
    if (!queue->items) {
        printf("Memory allocation failed for items!\n");
        free(queue); // Clean up partially allocated memory
        return NULL;
    }
    return queue;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->size == 0);
}

// Function to add a student to the queue (enqueue)
void enqueue(struct CircularQueue* queue, struct Student student) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    // Move rear in a circular manner
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->items[queue->rear] = student;
    queue->size = queue->size + 1;
    printf("Student %s (Roll No: %d) enqueued successfully.\n", student.name, student.rollNo);
}

// Function to remove a student from the queue (dequeue)
struct Student dequeue(struct CircularQueue* queue) {
    struct Student emptyStudent = {-1, "N/A", -1.0}; // Return value for an empty queue
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return emptyStudent;
    }
    struct Student student = queue->items[queue->front];
    // Move front in a circular manner
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return student;
}

// Function to display the elements of the queue
void display(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("\n--- Students in Queue ---\n");
    int i;
    // Iterate from front to rear
    for (i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("Position %d -> Roll No: %d, Name: %s, Mark: %.2f\n",
               i + 1,
               queue->items[index].rollNo,
               queue->items[index].name,
               queue->items[index].mark);
    }
    printf("-------------------------\n");
}

int main() {
    int capacity, choice;
    printf("Enter the capacity of the student queue: ");
    scanf("%d", &capacity);

    struct CircularQueue* queue = createQueue(capacity);
    if (!queue) return 1; // Exit if queue creation failed

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Add Student (Enqueue)\n");
        printf("2. Remove Student (Dequeue)\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (isFull(queue)) {
                    printf("Queue is full.\n");
                    break;
                }
                struct Student newStudent;
                printf("Enter Roll No: ");
                scanf("%d", &newStudent.rollNo);
                printf("Enter Name: ");
                // Clear input buffer before reading string
                while(getchar() != '\n'); 
                fgets(newStudent.name, MAX_NAME_LEN, stdin);
                newStudent.name[strcspn(newStudent.name, "\n")] = 0; // Remove trailing newline
                printf("Enter Mark: ");
                scanf("%f", &newStudent.mark);
                enqueue(queue, newStudent);
                break;
            }
            case 2: {
                if (!isEmpty(queue)) {
                    struct Student dequeuedStudent = dequeue(queue);
                    printf("Dequeued -> Roll No: %d, Name: %s, Mark: %.2f\n",
                           dequeuedStudent.rollNo,
                           dequeuedStudent.name,
                           dequeuedStudent.mark);
                } else {
                     printf("Queue is already empty.\n");
                }
                break;
            }
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting program.\n");
                free(queue->items); // Free the array
                free(queue);        // Free the queue structure
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}