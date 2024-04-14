#include <stdio.h>
#include  <stdlib.h>

struct node{
	int data;
	struct node *NEXT;
};
struct node *HEAD = NULL;

struct node *createnewnode(){
	struct node *p = (struct node*) malloc(sizeof(struct node));
	printf("\nEnter the data:");
	scanf("%d",p->data);
	p->NEXT = NULL;
	return p;
}
void insertfront(){
	struct node *p = createnewnode();
	if(HEAD==NULL){
		HEAD=p;
		return;
	}
	p->NEXT=HEAD;
	HEAD = p;
}

void insertend(){
	struct node *p = createnewnode();
	if(HEAD==NULL){
		HEAD=p;
		return;
	}
	struct node *tmp = HEAD;
	p->NEXT = NULL;
	while(tmp->NEXT!=NULL){
		tmp=tmp->NEXT;
	}
	tmp->NEXT=p;
}
void displayall(){
	struct node *p = HEAD;
	if (p == NULL) {
        printf("\nEmpty");
        return;
    }
	do{
		printf("%d",p->data);
		p=p->NEXT;
	}while(p->NEXT!=NULL);
	printf("%d",p->data);
}
void main(){
	int choice;
	do{
		
		system("cls");
		printf("1.\nInsert Front\n");
		printf("2.\nInsert End\n");
		printf("3.\nDisplay\n");
		printf("0.\nEXIT\n");
		printf("\nWhich choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1: insertfront();break;
			case 2: insertend();break;
			case 3: displayall();break;
			case 0: exit(0);
			default: printf("Invalid");
		}	
	}while(1);
}getch();








