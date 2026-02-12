#include <stdio.h>
#include <stdlib.h>



struct CircularQueue {
    int front, rear, size;
    unsigned capacity;
    int* arr;
};

struct CircularQueue* createQueue(unsigned capacity) {
    struct CircularQueue* q = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

int isFull(struct CircularQueue* q) {
    return (q->size == q->capacity);
}

int isEmpty(struct CircularQueue* q) {
    return (q->size == 0);
}

void Allocate(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot allocate.\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size = q->size + 1;
}

int Free(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot free.\n");
        return -1;
    }
    int item = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}

void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements (oldest to newest): ");
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->arr[(q->front + i) % q->capacity]);
    }
    printf("\n");
}

int main() {
    int n, num_slots;
    
    printf("Enter queue capacity: ");
    scanf("%d", &n);

    int free_space = n; 
    struct CircularQueue* q = createQueue(n);

    int choice;
    while (1) {
        
        printf("Total Capacity: %d | Occupied Slots: %d | Free Space: %d\n", n, q->size, free_space);
        printf("1. Allocate\n2. Free\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of slots to allocate: ");
                scanf("%d", &num_slots);

                if (num_slots > n) {
                    printf("Error: Cannot allocate %d slots. Total capacity is only %d.\n", num_slots, n);
                    break;
                }

                
                if (free_space < num_slots) {
                    int slots_to_free = num_slots - free_space;
                    printf("Not enough space. Freeing %d oldest slot\n", slots_to_free);
                    
                    for (int i = 0; i < slots_to_free; i++) {
                        Free(q);
                    }
                    
                    free_space += slots_to_free;
                }

                for (int i = 0; i < num_slots; i++) {
                    Allocate(q, 1);
                }
                
            
                free_space -= num_slots; 
                printf("Successfully allocated %d slot(s).\n", num_slots);
                break;

            case 2:
                printf("Enter the number of slots to Free: ");
                scanf("%d", &num_slots);
                
                if (q->size < num_slots) {
                    printf("Error: Cannot free %d slots. Only %d are occupied.\n", num_slots, q->size);
                } else {
                    for (int i = 0; i < num_slots; i++) {
                        Free(q);
                    }
                    free_space += num_slots;
                    printf("Successfully freed %d slot(s).\n", num_slots);
                }
                break;

            case 3:
                display(q);
                break;
                
            case 4: 
                printf("Exiting program.\n");
                free(q->arr);
                free(q);
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}