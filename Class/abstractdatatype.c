#include <stdio.h>
#define SIZE 5 // stack size

void push(int);
int pop();
void list();
int isempty();
int isfull();

int stack[SIZE];
int top = -1; // Initialize top to -1

int main()
{
    char choice;
    int k, res;

    do
    {
        printf("\nStack based on array!\n");
        printf("----------------------\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. LIST\n");
        printf("4. EXIT\n");
        printf("\nWhich operation? ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            printf("\nEnter a data number: ");
            scanf("%d", &k);
            push(k);
            break;
        case '2':
            res = pop();
            if (res == -1)
            {
                printf("\nStack is Empty!\n");
            }
            else
            {
                printf("\n%d is popped from stack\n", res);   
            }
            break;
        case '3':
            list();
            break;
        case '4':
            printf("\nThank You! BYE BYE!\n");
            return 0;
        default:
            printf("\nInvalid choice! Please enter a valid option.\n");
            break;
        }

    } while (1);

    return 0;
}

void push(int k)
{
    if (isfull())
    {
        printf("\nSORRY!! Stack is Full\n");
        return;
    }

    stack[++top] = k; // Increment top before assigning value
}

int pop()
{
    if (isempty())
    {
        printf("\nStack is Empty!\n");
        return -1; // Return -1 to indicate an empty stack
    }

    return stack[top--]; // Return top element and then decrement top
}

void list()
{
    int i;
    if (isempty())
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nStack Contents:\n");
        for (i = 0; i <= top; i++)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int isempty()
{
    return (top == -1);
}

int isfull()
{
    return (top == SIZE - 1);
}

