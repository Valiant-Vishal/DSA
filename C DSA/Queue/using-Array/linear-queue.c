/*
Procedure for Linear Queue

1. Start

2. Initialize front = -1, rear = -1.

3. Enqueue (Insert):
    -If rear == MAX-1 → Overflow.
    -Else if front == -1 → set front = 0.
    -Increment rear and insert element at queue[rear].

4. Dequeue (Delete):
    -If front == -1 → Underflow.
    -Else print queue[front].
    -If front == rear → set front = rear = -1.
    -Else increment front.

5. Peek:
    -If front == -1 → Queue empty.
    -Else show queue[front].

6. Display:
    -If front == -1 → Queue empty.
    -Else print elements from front to rear.

7. Stop

*/


#include <stdio.h>
#include <stdlib.h>
#define MAX 50   // maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to check if queue is full
int isFull() {
    return (rear == MAX - 1);
}

// Function to insert element into queue
void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", data);
        return;
    }
    if (front == -1)  // if inserting first element
        front = 0;
    rear++;
    queue[rear] = data;
    printf("%d enqueued to queue\n", data);
}

// Function to delete element from queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to delete\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front]);
    if (front == rear) {
        // only one element was present
        front = rear = -1;
    } else {
        front++;
    }
}

// Function to show front element
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

// Function to display all elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Linear Queue Menu ---\n");
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
