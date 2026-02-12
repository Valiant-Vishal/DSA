/*
Step 1: Initialization:
    -Input capacity (size of queue).
    -Allocate memory:
        - arr = malloc(capacity * sizeof(int))
        - front = -1, rear = -1, size = 0.

Step 2: Enqueue(x)
    -If size == capacity → Overflow.
    -Else if front == -1 → set front = 0.
    -rear = (rear + 1) % capacity.
    -arr[rear] = x.
    -Increment size.

Step 3: Dequeue()
    -If size == 0 → Underflow.
    -Else print arr[front].
    -If (front == rear) → set front = rear = -1.
    -Else front = (front + 1) % capacity.
    -Decrement size.

Step 4: Peek()
    -If size == 0 → Queue empty.
    -Else return arr[front].

Step 5: Display()
    -If size == 0 → Queue empty.
    -Else: 
        - Start from i = front.
        -Print elements while moving (i + 1) % capacity until i == rear.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for Circular Queue
struct CircularQueue {
    int *arr;
    int front, rear, size, capacity;
};

// Function to create circular queue
struct CircularQueue* createQueue(int capacity) {
    struct CircularQueue* q = (struct CircularQueue*) malloc(sizeof(struct CircularQueue));
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->size = 0;
    q->arr = (int*) malloc(capacity * sizeof(int));
    return q;
}

// Check if queue is full
int isFull(struct CircularQueue* q) {
    return (q->size == q->capacity);
}

// Check if queue is empty
int isEmpty(struct CircularQueue* q) {
    return (q->size == 0);
}

// Enqueue
void enqueue(struct CircularQueue* q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d\n", data);
        return;
    }
    if (q->front == -1) // inserting first element
        q->front = 0;

    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = data;
    q->size++;
    printf("%d enqueued\n", data);
}

// Dequeue
void dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Nothing to delete\n");
        return;
    }
    printf("%d dequeued\n", q->arr[q->front]);
    if (q->front == q->rear) {
        // only one element left
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->capacity;
    }
    q->size--;
}

// Peek
void peek(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", q->arr[q->front]);
    }
}

// Display
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->capacity;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter queue capacity: ");
    scanf("%d", &n);

    struct CircularQueue* q = createQueue(n);

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
                enqueue(q, value);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                display(q);
                break;
            case 5:
                free(q->arr);
                free(q);
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
