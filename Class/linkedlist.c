#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// declare the structure representing a node
struct node {
    int data;
    struct node *NEXT;
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
        printf("\n4. Delete Front");
        printf("\n5. Delete End");
        printf("\n6. insertafter");
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
            case 4:
            	deletefront();break;
            	
            case 5: 
            	deleteend();break;
            case 6:
            		insertafter();break;
            case 0:
                exit(0);
            default:
                printf("\nInvalid Choice! Please try again.");
        }
        getch();
    } while (choice!=0);
}

struct node *createnewnode() {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &p->data);fflush(stdin);
    p->NEXT = NULL;
    return p;
}

void insertfront() {
    struct node *p = createnewnode();
    if (HEAD == NULL) {
        HEAD = p;	
        return;
    }
    p ->NEXT = HEAD;
    HEAD = p;
}

void insertend() {
    struct node *p = createnewnode();
    if (HEAD == NULL) {
        HEAD = p;
        return;
    }

    struct node *temp = HEAD;
    while (temp->NEXT != NULL) {
        temp = temp->NEXT;
    }
    temp->NEXT = p;
}

void displayall() {
    struct node *p = HEAD;
    if (p == NULL) {
        printf("\nEmpty");
        return;
    }

    while (p->NEXT != NULL) {
        printf("%d\t", p->data);
        p = p->NEXT;
    }
    printf("%d", p->data);
}
void deletefront()
{
	struct node*tmp;
	if (HEAD==NULL)
	{
		printf("\nEmpty List!\n");
		getch();
		return;
	}
	tmp=HEAD;
	HEAD=HEAD->NEXT;
	free(tmp);
}

void deleteend()
{
	struct node*p;
	if (HEAD==NULL)
	{
		printf("\nEmpty List!\n");
		getch();
		return;
	}
	else if(HEAD->NEXT==NULL){
		free(HEAD);
		HEAD=NULL;
		return;
	}
	else{
		p=HEAD;
		while(p->NEXT->NEXT!= NULL){
		p=p->NEXT;
	}
		free (p->NEXT);
		p->NEXT=NULL;
	}
	
}

void insertafter(){
	struct node *tmp,*tmp1;
	int k;
	printf("Enter the number after which you want to add the next number: ");
	scanf("%d",&k);
	struct node *p = createnewnode();
	
	if(HEAD==NULL){
		HEAD = p;
		return;
	}
	tmp = HEAD;
	while (tmp!=NULL){
		if(tmp->data == k){
			p->NEXT = tmp->NEXT;
			tmp->NEXT = p;
			return;
		}
		tmp1 = tmp;
		tmp = tmp->NEXT;
	}
	tmp1->NEXT = tmp;
}


