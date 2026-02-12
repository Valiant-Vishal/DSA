/*
Procedure for Double Ended Queue (Deque)

Step 1: Initialization
    -Set front = -1, rear = -1.
    -Define MAX (capacity of deque).

Step 2: InsertFront(x)
    -If deque is full → Overflow.
    -If front == -1 → set front = rear = 0.
    -Else if front == 0 → set front = MAX - 1.
    -Else front = front - 1.
    -Place element at deque[front].

Step 3: InsertRear(x)
    -If deque is full → Overflow.
    -If front == -1 → set front = rear = 0.
    -Else if rear == MAX - 1 → set rear = 0.
    -Else rear = rear + 1.
    -Place element at deque[rear].

Step 4: DeleteFront()
    -If deque is empty → Underflow.
    -Print deque[front].
    -If front == rear → set front = rear = -1.
    -Else if front == MAX - 1 → set front = 0.
    -Else front = front + 1.

Step 5: DeleteRear()
    -If deque is empty → Underflow.
    -Print deque[rear].
    -If front == rear → set front = rear = -1.
    -Else if rear == 0 → set rear = MAX - 1.
    -Else rear = rear - 1.

Step 6: Display()
    -If deque is empty → Print "Deque empty".
    -Else:
        -Start from front.
        -Print elements one by one while moving (i + 1) % MAX until reaching rear.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5   // maximum size of deque

int deque[MAX];
int front = -1, rear = -1;

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Check if full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Insert at front
void insertFront(int x) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d\n", x);
        return;
    }
    if (front == -1) {  // empty deque
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front = front - 1;
    }
    deque[front] = x;
    printf("%d inserted at front\n", x);
}

// Insert at rear
void insertRear(int x) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d\n", x);
        return;
    }
    if (front == -1) {  // empty deque
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear = rear + 1;
    }
    deque[rear] = x;
    printf("%d inserted at rear\n", x);
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Nothing to delete\n");
        return;
    }
    printf("%d deleted from front\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front = front + 1;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Nothing to delete\n");
        return;
    }
    printf("%d deleted from rear\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear = rear - 1;
    }
}

// Display
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Double Ended Queue Menu ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
