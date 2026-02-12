/*
Step 1 : Initialize an empty stack (for operators) and an empty postfix string.

Step 2 : Scan the infix expression one character (item) at a time.

Step 3 : If item is an operand (letter/number), append it to the postfix string.

Step 4 : If item is '(', push it onto the stack.

Step 5 : If item is ')', pop from stack to postfix until '(' is encountered, then discard the '('.

Step 6 : If item is an operator, pop all operators from the stack with higher or equal precedence to postfix, then push the current item onto the stack.

Step 7 : Once infix is finished, pop any remaining items from the stack and append them to postfix.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isalnum()

#define MAX_STACK_SIZE 100

// --- Global Stack Implementation ---
char stack[MAX_STACK_SIZE];
int top = -1;

void push(char item) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = item;
    }
}


char pop() {
    if (top == -1) {
        return -1; // Indicates stack underflow
    } else {
        return stack[top--];
    }
}


int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^': // Exponentiation
            return 3;
        default:
            return 0; // For non-operators like '('
    }
}

// --- Main Infix to Postfix Conversion ---

int main() {
    char infix_exp[MAX_STACK_SIZE];
    char postfix_exp[MAX_STACK_SIZE];
    int i, j = 0; // i = infix index, j = postfix index
    char item;

    printf("Enter the infix expression: ");
    scanf("%s", infix_exp);

    // Iterate through the entire infix expression
    for (i = 0; infix_exp[i] != '\0'; i++) {
        item = infix_exp[i];

        // Case 1: Operand (letter or digit)
        if (isalnum(item)) {
            postfix_exp[j++] = item; // Add to postfix string
        
        // Case 2: Opening parenthesis
        } else if (item == '(') {
            push(item); // Push onto stack
        
        // Case 3: Closing parenthesis
        } else if (item == ')') {
            // Pop operators until '(' is found
            while (top != -1 && stack[top] != '(') {
                postfix_exp[j++] = pop();
            }
            // Pop the '(' itself
            if (top != -1 && stack[top] == '(') {
                pop(); 
            }
        
        // Case 4: Operator
        } else {
            // Pop higher or equal precedence operators from stack
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix_exp[j++] = pop();
            }
            // Push the current operator onto the stack
            push(item);
        }
    }

    // After scanning infix, pop remaining operators from stack
    while (top != -1) {
        postfix_exp[j++] = pop();
    }

    // Null-terminate the postfix string
    postfix_exp[j] = '\0';

    printf("Postfix expression: %s\n", postfix_exp);

    return 0;
}