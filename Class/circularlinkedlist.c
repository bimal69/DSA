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
void deleteend();
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
    } while (1);
}

struct node *createnewnode() {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &p->data);
    p->NEXT = NULL;
    return p;
}

void insertfront(){
    struct node *p,*q; 
	 p = createnewnode();
    if (HEAD == NULL){
        p->NEXT = q;
        HEAD = p;
        return;
    }
    q=HEAD;
    while(q->NEXT!=HEAD){
    	q = q->NEXT;
	}	
    p->NEXT = p;
    p->NEXT = HEAD;
    HEAD = p;
}


void insertend() {
    struct node *p,*q;
	p = createnewnode();
    if (HEAD == NULL) {
    	p->NEXT =p;
        HEAD = p;
        return;
    }
	
    q= HEAD;
    while (q->NEXT!= NULL) {
        q = q->NEXT;
        p->NEXT = HEAD;
    }
    q->NEXT = p;
    p->NEXT = HEAD;
}

void displayall() {
    struct node *p = HEAD;
    if (p == NULL) {
        printf("\nEmpty");
        return;
    }

    while (p->NEXT!= NULL) {
        printf("%d\t", p->data);
        p = p->NEXT;
    }
    printf("%d", p->data);
}
void deletefront()
{
	struct node *tmp,*p;
	if (HEAD==NULL)
	{
		printf("\nEmpty List!\n");
		getch();
		return;
	}
	if(HEAD->NEXT==HEAD){
		free(HEAD);
		HEAD = NULL;
	}
	
	while (tmp->NEXT !=NULL){
	 	tmp=tmp->NEXT;
	}
	p=HEAD;
	tmp->NEXT = HEAD->NEXT;
	HEAD = HEAD->NEXT;
	free(p);
	
	
}

void deleteend()
{
	struct node *tmp,*p;
	if (HEAD==NULL)
	{
		printf("\nEmpty List!\n");
		getch();
		return;
	}
	if(HEAD->NEXT==HEAD){
		free(HEAD);
		HEAD = NULL;
	}
	
	while (p->NEXT->NEXT!=HEAD){
	 	p=p->NEXT;
	}
	p=HEAD;
	free(p->NEXT);
	p->NEXT = HEAD;
	
}



