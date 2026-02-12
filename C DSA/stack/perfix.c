/*
1. Initialize a Stack: Create an empty stack.

2. Scan the Expression: Read the expression from right to left, one token (number or operator) at a time.

3. Process Each Token:
    -If the token is a number: Push it onto the stack.
    -If the token is an operator:
       *Pop the top two numbers from the stack. The first is operand1, and the second is operand2.
       *Perform the operation: operand1 (operator) operand2. Note the order is crucial.
       *Push the result back onto the stack.

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
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = value;
}

// Pop an item from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

int evaluatePrefix(char* expression) {
    Stack s;
    initialize(&s);
    int len = strlen(expression);
    char token[MAX_SIZE];
    int i = len - 1;

    // We can't use strtok easily here because we are traversing backwards.
    // Instead, we'll manually parse the expression from right to left.
    while (i >= 0) {
        // Skip spaces from the right
        while (i >= 0 && expression[i] == ' ') {
            i--;
        }

        if (i < 0) break;

        char c = expression[i];

        if (isdigit(c) || (c == '-' && i > 0 && isdigit(expression[i-1]))) {
            // It's a number (can be negative). Read the full number.
            int end_idx = i;
            while (i >= 0 && (isdigit(expression[i]) || (expression[i] == '-' && i > 0 && !isdigit(expression[i-1])))) {
                i--;
            }
            // Extract the number string
            strncpy(token, &expression[i + 1], end_idx - i);
            token[end_idx - i] = '\0';
            push(&s, atoi(token));
        } else {
            // It's an operator
            int operand1 = pop(&s);
            int operand2 = pop(&s);
            int result;

            switch (c) {
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
                    printf("Invalid operator: %c\n", c);
                    exit(EXIT_FAILURE);
            }
            push(&s, result);
        }
        i--;
    }

    if (s.top != 0) {
        printf("Invalid expression format.\n");
        exit(EXIT_FAILURE);
    }
    return pop(&s);
}

// Main function to test the code
int main() {
    char expr[MAX_SIZE];
    printf("Enter a prefix expression (e.g., '+ 2 3' or '* + 2 3 4'): ");
    if (fgets(expr, sizeof(expr), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    expr[strcspn(expr, "\n")] = 0;

    printf("Prefix expression: %s\n", expr);
    int result = evaluatePrefix(expr);
    printf("Result: %d\n", result);

    return 0;
}