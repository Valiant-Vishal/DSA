/*
1. Initialization 
    - Input capacity of deque.
    - Allocate memory dynamically:
        - arr = malloc(capacity * sizeof(int)).
        - Set front = -1, rear = -1, size = 0.

2. InsertFront(x)
    - If size == capacity → Overflow.
    - If deque is empty → front = rear = 0.
    - Else if front == 0 → set front = capacity - 1.
    - Else front = front - 1.
    - Store arr[front] = x, increase size.

3. InsertRear(x)
    - If size == capacity → Overflow.
    - If deque is empty → front = rear = 0.
    - Else if rear == capacity - 1 → set rear = 0.
    - Else rear = rear + 1.
    - Store arr[rear] = x, increase size.

4. DeleteFront()
    - If size == 0 → Underflow.
    - Print arr[front].
    - If front == rear → set front = rear = -1.
    - Else if front == capacity - 1 → set front = 0.
    - Else front = front + 1.
    - Decrease size.

5. DeleteRear()
    - If size == 0 → Underflow.
    - Print arr[rear].
    - If front == rear → set front = rear = -1.
    - Else if rear == 0 → set rear = capacity - 1.
    - Else rear = rear - 1.
    - Decrease size.

6. Display()
    - If size == 0 → Print "Deque empty".
    - Else start at i = front.
    - Print elements until reaching rear, using (i + 1) % capacity.
*/


#include <stdio.h>
#include <stdlib.h>

struct Deque {
    int *arr;
    int front, rear, size, capacity;
};

// Create deque dynamically
struct Deque* createDeque(int capacity) {
    struct Deque* dq = (struct Deque*) malloc(sizeof(struct Deque));
    dq->capacity = capacity;
    dq->front = dq->rear = -1;
    dq->size = 0;
    dq->arr = (int*) malloc(capacity * sizeof(int));
    return dq;
}

// Check if empty
int isEmpty(struct Deque* dq) {
    return (dq->size == 0);
}

// Check if full
int isFull(struct Deque* dq) {
    return (dq->size == dq->capacity);
}

// Insert at front
void insertFront(struct Deque* dq, int x) {
    if (isFull(dq)) {
        printf("Deque Overflow! Cannot insert %d\n", x);
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = dq->capacity - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = x;
    dq->size++;
    printf("%d inserted at front\n", x);
}

// Insert at rear
void insertRear(struct Deque* dq, int x) {
    if (isFull(dq)) {
        printf("Deque Overflow! Cannot insert %d\n", x);
        return;
    }
    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == dq->capacity - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = x;
    dq->size++;
    printf("%d inserted at rear\n", x);
}

// Delete from front
void deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow! Nothing to delete\n");
        return;
    }
    printf("%d deleted from front\n", dq->arr[dq->front]);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == dq->capacity - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
    dq->size--;
}

// Delete from rear
void deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow! Nothing to delete\n");
        return;
    }
    printf("%d deleted from rear\n", dq->arr[dq->rear]);

    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = dq->capacity - 1;
    } else {
        dq->rear--;
    }
    dq->size--;
}

// Display
void display(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % dq->capacity;
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter capacity of deque: ");
    scanf("%d", &n);

    struct Deque* dq = createDeque(n);

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
                insertFront(dq, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(dq, value);
                break;
            case 3:
                deleteFront(dq);
                break;
            case 4:
                deleteRear(dq);
                break;
            case 5:
                display(dq);
                break;
            case 6:
                free(dq->arr);
                free(dq);
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
