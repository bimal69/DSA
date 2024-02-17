#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

void convert_to_infix(char *postfix) {
    char *infix = (char *)malloc((strlen(postfix) + 1) * sizeof(char));
    int i = 0, j = 0;

    while (postfix[i] != '\0') {
        if (isalnum(postfix[i])) {
            infix[j++] = postfix[i++];
        } else if (is_operator(postfix[i])) {
            char op2 = pop();
            char op1 = pop();
            infix[j++] = '(';
            infix[j++] = op1;
            infix[j++] = postfix[i++];
            infix[j++] = op2;
            infix[j++] = ')';
            push(infix[j - 1]); // Push the result back onto the stack
        } else {
            // Skip spaces
            i++;
        }
    }

    infix[j] = '\0';
    printf("Postfix: %s\n", postfix);
    printf("Infix: %s\n", infix);
    free(infix);
}

int main() {
    char postfix[SIZE];

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    convert_to_infix(postfix);

    return 0;
}

