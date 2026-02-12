/*

1. Initialize a Stack: Create an empty stack.

2. Scan the Expression: Read the expression from left to right, one token (number or operator) at a time.

3. Process Each Token:
    -If the token is a number: 
        -Push it onto the stack.
    -If the token is an operator:
        -Pop the top two numbers from the stack. The first is operand2, and the second is operand1.
        -Perform the operation: operand1 (operator) operand2.
        -Push the result back onto the stack.

4. Final Result: After processing all tokens, the last number remaining on the stack is the final result.
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Initialize the stack
void initialize(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push an item onto the stack
void push(Stack* s, int value) {
    if (s->top >= MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++s->top] = value;
}

// Pop an item from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE); // Use exit to terminate on critical error
    }
    return s->items[s->top--];
}

int evaluatePostfix(char* expression) {
    Stack s;
    initialize(&s);
    char *token;

    // Use strtok to tokenize the string based on spaces
    token = strtok(expression, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // It's a number (can be negative)
            push(&s, atoi(token));
        } else {
            // It's an operator
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result;

            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    // Handle division by zero
                    if (operand2 == 0) {
                        printf("Error: Division by zero!\n");
                        exit(EXIT_FAILURE);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %s\n", token);
                    exit(EXIT_FAILURE);
            }
            push(&s, result);
        }
        // Get the next token
        token = strtok(NULL, " ");
    }
    
    // The final result is the only item left on the stack
    if (s.top != 0) {
        printf("Invalid expression format.\n");
        exit(EXIT_FAILURE);
    }
    return pop(&s);
}

// Main function to test the code
int main() {
    char expr[MAX_SIZE];
    printf("Enter a postfix expression (e.g., '23 34 + 45 *'): ");
    
    // Use fgets for safer input
    if (fgets(expr, sizeof(expr), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    
    // Remove the trailing newline character from fgets
    expr[strcspn(expr, "\n")] = 0;

    printf("Postfix expression: %s\n", expr);
    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);
    
    return 0;
}