#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

// Function prototypes
void push(char);
char pop();
int is_operator(char);
int precedence(char);
void infix_to_prefix(char[], char[]);

// Main function
int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    // Input infix expression from the user
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert infix to prefix
    infix_to_prefix(infix, prefix);

    // Output the prefix expression
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

// Function to push an element onto the stack
void push(char item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}

// Function to pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

// Function to check if a character is an operator
int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to determine the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix to prefix
void infix_to_prefix(char infix[], char prefix[]) {
    int i, j;
    char ch, temp;

    // Reverse the infix expression
    strrev(infix);

    // Scan infix expression from right to left
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
            i++;
        } else if (infix[i] == ')') {
            infix[i] = '(';
            i++;
        }
    }

    // Infix to prefix conversion
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while ((ch = pop()) != '(') {
                prefix[j++] = ch;
            }
        } else {
            while (precedence(stack[top]) >= precedence(infix[i])) {
                prefix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop any remaining operators from the stack
    while (top != -1) {
        prefix[j++] = pop();
    }

    // Null-terminate the prefix expression
    prefix[j] = '\0';

    // Reverse the prefix expression to get the final result
    strrev(prefix);
}

