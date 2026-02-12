#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Algorithm for Stack Operations
1. Push (Add)
Check for full: If the stack is at its maximum capacity, report "Stack Overflow."

Insert: Otherwise, increment the top index and place the new element at this position.

2. Pop (Remove)
Check for empty: If the stack is empty, report "Stack Underflow" and return a sentinel value.

Remove: Otherwise, retrieve the element at the top index, then decrement the top index.

Return: Return the retrieved element.

3. Peek (View Top)
Check for empty: If the stack is empty, report an error and return a sentinel value.

Return: Otherwise, return the element at the top index without changing the top index.

4. Create Stack
Allocate memory for the stack structure and its internal dynamic array.

Initialize top to -1 and set the capacity.
*/


// Structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack of given capa  city
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

// Function to get top item from stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

// Function to display the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to get the size of the stack
int size(struct Stack* stack) {
    return stack->top + 1;
}

// Driver program to test above functions
int main() {
    struct Stack* stack = createStack(100);
    
    printf("=== Stack Implementation in C ===\n\n");
    
    // Test push operations
    push(stack, 10);
    push(stack, 20);
    
    push(stack, 30);
    push(stack, 40);
    
    printf("\nCurrent ");
    display(stack);
    
    // Test peek
    printf("\nTop element is %d\n", peek(stack));
    
    // Test pop operations
    printf("\nPopped element is %d\n", pop(stack));
    printf("Popped element is %d\n", pop(stack));
    
    printf("\nCurrent ");
    display(stack);
    
    // Test size
    printf("\nCurrent size of stack: %d\n", size(stack));
    
    // Test more operations
    push(stack, 50);
    push(stack, 60);
    
    printf("\nAfter adding more elements:\n");
    display(stack);
    
    // Test edge cases
    printf("\nTesting edge cases:\n");
    while (!isEmpty(stack)) {
        printf("Popped: %d\n", pop(stack));
    }
    
    printf("\nTrying to pop from empty stack:\n");
    pop(stack);
    
    free(stack->array);
    free(stack);
    
    return 0;
}
