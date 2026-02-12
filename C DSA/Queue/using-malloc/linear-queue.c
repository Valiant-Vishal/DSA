/*
1. Initialization
    -Input capacity (queue size).
    -Allocate memory dynamically:
        - arr = malloc(capacity * sizeof(int))
        - front = 0, rear = -1, size = 0.

2. Enqueue(x)
    - If size == capacity → Overflow.
    - Else:
        - rear = rear + 1
        - arr[rear] = x
        - size++

3. Dequeue()
    - If size == 0 → Underflow.
    - Else:
        - Print arr[front].
        - Shift all elements left: arr[i] = arr[i+1] for i = 0 to rear-1.
        - rear--, size--.

4. Peek()
    - If size == 0 → Queue empty.
    - Else return arr[front].

5. Display()
    - If size == 0 → Queue empty.
    - Else print elements from index front to rear.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for Linear Queue
struct Queue {
    int *arr;
    int front, rear, size, capacity;
};

// Function to create queue
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = -1;
    q->arr = (int*) malloc(capacity * sizeof(int));
    return q;
}

// Check if full
int isFull(struct Queue* q) {
    return (q->size == q->capacity);
}

// Check if empty
int isEmpty(struct Queue* q) {
    return (q->size == 0);
}

// Enqueue (Insert)
void enqueue(struct Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert %d\n", data);
        return;
    }
    q->arr[++q->rear] = data;
    q->size++;
    printf("%d enqueued\n", data);
}

// Dequeue (Delete)
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Nothing to delete\n");
        return;
    }
    printf("%d dequeued\n", q->arr[q->front]);

    // shift elements left (because linear queue)
    for (int i = 0; i < q->rear; i++) {
        q->arr[i] = q->arr[i + 1];
    }
    q->rear--;
    q->size--;
}

// Peek (Front element)
void peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", q->arr[q->front]);
    }
}

// Display
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter queue capacity: ");
    scanf("%d", &n);

    struct Queue* q = createQueue(n);

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
