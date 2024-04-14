#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> // Include string.h for strlen function

// Define maximum stack size
#define MAX_STACK_SIZE 100

// Define stack structure
struct Stack {
    int top;
    int items[MAX_STACK_SIZE];
};

// Function to initialize stack
void initializeStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

// Function to check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to push element onto stack
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++s->top] = value;
}

// Function to pop element from stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char *expression) {
    struct Stack s;
    initializeStack(&s);
    int i, operand1, operand2;

    // Length of the expression
    int len = strlen(expression);

    for (i = 0; i < len; i++) {
        if (expression[i] == ' ') {
            continue; // Skip spaces
        }
        if (isdigit(expression[i])) {
            // Extracting digits
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--; // To compensate for the extra increment in the loop
            push(&s, num);
        } else {
            operand2 = pop(&s);
            operand1 = pop(&s);
            switch (expression[i]) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error\n");
                        exit(EXIT_FAILURE);
                    }
                    push(&s, operand1 / operand2);
                    break;
                default:
                    printf("Invalid expression\n");
                    exit(EXIT_FAILURE);
            }
        }
    }
    return pop(&s);
}

int main() {
    char postfixExpression[MAX_STACK_SIZE];
    printf("Enter postfix expression: ");
    fgets(postfixExpression, sizeof(postfixExpression), stdin);

    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);

    return 0;
}

