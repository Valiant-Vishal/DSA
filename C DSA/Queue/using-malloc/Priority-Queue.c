/*
1. Initialization:
    -Input capacity (max size of queue).

2. Allocate memory:
    -arr = malloc(capacity * sizeof(struct Element))
    -size = 0.

3. Enqueue(x, p)
    -If size == capacity → Overflow.
    - Else:
        -Insert arr[size].data = x.
        -Insert arr[size].priority = p.
        -Increment size.

4. Dequeue()
    -If size == 0 → Underflow.
    -Else:
        -Find index of element with highest priority.
        -Print and remove that element.
        -Shift all elements after it one step left.
        -Decrement size.

5. Peek()
    -If size == 0 → Queue empty.
    -Else:
        -Find element with highest priority.
        -Return arr[index].data.

6. Display()
    -If size == 0 → Queue empty.
    -Else print all elements as data:priority.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for Priority Queue element
struct Element {
    int data;
    int priority;
};

// Structure for Priority Queue
struct PriorityQueue {
    struct Element* arr;
    int capacity;
    int size;
};

// Function to create a priority queue
struct PriorityQueue* createQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*) malloc(sizeof(struct PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->arr = (struct Element*) malloc(capacity * sizeof(struct Element));
    return pq;
}

// Check if empty
int isEmpty(struct PriorityQueue* pq) {
    return (pq->size == 0);
}

// Check if full
int isFull(struct PriorityQueue* pq) {
    return (pq->size == pq->capacity);
}

// Enqueue
void enqueue(struct PriorityQueue* pq, int data, int priority) {
    if (isFull(pq)) {
        printf("Queue Overflow! Cannot insert %d\n", data);
        return;
    }
    pq->arr[pq->size].data = data;
    pq->arr[pq->size].priority = priority;
    pq->size++;
    printf("%d (priority %d) enqueued\n", data, priority);
}

// Dequeue (remove element with highest priority)
void dequeue(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue Underflow! Nothing to delete\n");
        return;
    }

    // Find element with highest priority
    int highestPriority = pq->arr[0].priority;
    int index = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i].priority > highestPriority) {
            highestPriority = pq->arr[i].priority;
            index = i;
        }
    }

    printf("%d (priority %d) dequeued\n", pq->arr[index].data, pq->arr[index].priority);

    // Shift remaining elements left
    for (int i = index; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;
}

// Peek (show highest priority element)
void peek(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty\n");
        return;
    }

    int highestPriority = pq->arr[0].priority;
    int index = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->arr[i].priority > highestPriority) {
            highestPriority = pq->arr[i].priority;
            index = i;
        }
    }
    printf("Front element: %d (priority %d)\n", pq->arr[index].data, pq->arr[index].priority);
}

// Display
void display(struct PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements (data:priority): ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d:%d ", pq->arr[i].data, pq->arr[i].priority);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter queue capacity: ");
    scanf("%d", &n);

    struct PriorityQueue* pq = createQueue(n);

    int choice, value, priority;
    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &value, &priority);
                enqueue(pq, value, priority);
                break;
            case 2:
                dequeue(pq);
                break;
            case 3:
                peek(pq);
                break;
            case 4:
                display(pq);
                break;
            case 5:
                free(pq->arr);
                free(pq);
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
