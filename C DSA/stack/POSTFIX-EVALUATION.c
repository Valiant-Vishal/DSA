/*
Step 1:Initialize an empty stack to hold operands.

Step 2:Scan the postfix expression from left to right, one symbol at a time.

Step 3:If the symbol is a digit (operand), convert it to an integer and push it onto the stack.

Step 4:If the symbol is an operator:

Step 5:Pop two operands (e.g., b, then a) from the stack, perform the operation (a operator b), and push the result back onto the stack.

Step 6:After the expression is finished, the final result is the only value left on the stack; pop it.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h> 
#include <math.h>   

#define MAX_STACK_SIZE 100

// --- Global Stack Implementation ---
int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1); // Exit program on overflow
    }
    stack[++top] = value;
}


int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1); // Exit program on underflow
    }
    return stack[top--];
}

// --- Main Postfix Evaluation ---

int main() {
    char expression[MAX_STACK_SIZE];
    int i;
    int a, b; // Operands
    int result;
    char symbol;

    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    // Iterate through the expression string
    for (i = 0; expression[i] != '\0'; i++) {
        symbol = expression[i];

        // Case 1: If it's a digit (operand)
        if (isdigit(symbol)) {
            // Convert char digit to int digit (e.g., '5' -> 5)
            push(symbol - '0'); 
        
        // Case 2: If it's an operator
        } else {
            // Pop the top two operands
            // Note: Order matters for subtraction/division
            b = pop(); // 'b' is the second operand
            a = pop(); // 'a' is the first operand

            // Perform operation based on the symbol
            switch (symbol) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(a - b);
                    break;
                case '*':
                    push(a * b);
                    break;
                case '/':
                    push(a / b);
                    break;
                case '^':
                    push((int)pow(a, b)); // Use pow() and cast to int
                    break;
                default:
                    printf("Invalid operator: %c\n", symbol);
                    exit(1);
            }
        }
    }

    // The final result is the last item on the stack
    result = pop();

    // Check if the stack is empty (valid expression)
    if (top != -1) {
        printf("Error: Invalid postfix expression (too many operands).\n");
    } else {
        printf("Result: %d\n", result);
    }

    return 0;
}