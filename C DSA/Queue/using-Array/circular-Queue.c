/*
Procedure for Circular Queue

1. Initialization:
    -front = -1, rear = -1

2. Enqueue(x):
    -If ( (rear + 1) % MAX == front ) → Overflow
    -Else if (front == -1) → front = rear = 0
    -Else rear = (rear + 1) % MAX
    -Insert x at queue[rear]

4. Dequeue():
    -If (front == -1) → Underflow
    -Else print queue[front]
    -If (front == rear) → set front = rear = -1 (queue becomes empty)
    -Else front = (front + 1) % MAX

5. Peek():
    -If (front == -1) → Queue empty
    -Else return queue[front]

6. Display():
    -If (front == -1) → Queue empty
    -Else print from i = front to rear using (i + 1) % MAX
*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 5   // maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

// Check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Check if queue is full
int isFull() {
    return ((rear + 1) % MAX == front);
}

// Insert element
void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", data);
        return;
    }
    if (front == -1)  // inserting first element
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = data;
    printf("%d enqueued\n", data);
}

// Delete element
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to delete\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    if (front == rear) {
        // only one element present
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Show front element
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Display all elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
