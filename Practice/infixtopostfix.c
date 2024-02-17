#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

int priority(char x) {
    if (x == '(') {
        return 0;
    }
    if (x == '+' || x == '-') {
        return 1;
    }
    if (x == '*' || x == '/') {
        return 2;
    }
    return -1; // Added to handle potential non-operator characters
}

int isallnum(char x) {
    return isdigit(x); // Use isdigit from <ctype.h> to check if x is a digit
}

int main() {
    char exp[20];
    char *c;
    char x;

    printf("Enter the expression: ");
    scanf("%s", exp);
    c = exp;

    while (*c != '\0' && *c != ')') {
        if (isallnum(*c)) {
            printf("%c", *c);
        } else if (*c == '(') {
            push(*c);
        } else if (*c == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        } else {
            while (top != -1 && priority(stack[top]) >= priority(*c)) {
                printf("%c", pop());
            }
            push(*c);
        }
        c++;
    }

    while (top != -1) {
        printf("%c", pop());
    }

    return 0;
}

