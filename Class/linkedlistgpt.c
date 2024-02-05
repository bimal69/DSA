#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// declare the structure representing a node
struct node {
    int data;
    struct node *next;
};

void insertfront();
void insertend();
void deletefront();
void insertafter();
void displayall();
void search();

struct node *HEAD = NULL;

int main() {
    int choice;
    do {
        system("cls");
        printf("\n1. Insert Front");
        printf("\n2. Insert End");
        printf("\n3. Display All");
        printf("\n0. Exit");
        printf("\n\nWhich Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertfront();
                break;
            case 2:
                insertend();
                break;
            case 3:
                displayall();
                break;
            case 0:
                exit(0);
            default:
                printf("\nInvalid Choice! Please try again.");
        }
        getch();
    } while (1);
}

struct node *createnewnode() {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &p->data);fflush(stdin);
    p->next = NULL;
    return p;
}

void insertfront() {
    struct node *p = createnewnode();
    if (HEAD == NULL) {
        HEAD = p;
        return;
    }
    p->next = HEAD;
    HEAD = p;
}

void insertend() {
    struct node *p = createnewnode();
    if (HEAD == NULL) {
        HEAD = p;
        return;
    }

    struct node *temp = HEAD;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p;
}

void displayall() {
    struct node *p = HEAD;
    if (p == NULL) {
        printf("\nEmpty");
        return;
    }

    while (p->next != NULL) {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("%d", p->data);
}

