 //C implementatin of stack abstract data type (ADT) based on array
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5 //stack size 

int stack[SIZE];
int pop();
void list();
int isempty();
int isfull();
int top= -1;

void main(){
	char choice;
	int k,res;
	do{
		system("cls");
		printf("\nStack bases on Array!\n");
		printf("\n---------------------\n");
		printf("1.PUSH\t\t\n");
		printf("2.POP\t\t\n");
		printf("3.List\t\t\n");
		printf("4.EXIT\t\t\n");
		printf("\n\nWhich operation?");
		scanf("%c",&choice);
		fflush(stdin);
		switch(choice){
			case '1': printf("\nEnter a data number:\n");scanf("%d",&k);push(k);break;
			case '2': res=pop();
					if(res==1){
						printf("\n\nStack is empty");
					}
					else{
						printf("\n\n%d is popped from stack!\n\n",k);
					}
					break;
			case '3': list();break;
			case '4': printf("\n\nThanks ! bye");
			default : printf("\nInvalid");
		}
	}while (choice!='4');
	return 0;
}
void push(int k){
	if(isfull()){
		printf("\n\nSorry! stack is full\n\n");return;
	}
	stack[++top]=k;
}
int pop(){
	if(isempty()){
		printf("\n\nSorry! stack is empty");getch(); return;
	}
	return stack[top--];
}
void list(){
	int i;
	if(isempty()){
		printf("\n\nStack is empty!");
	}
	printf("\n\nStack contents: \n\n");
	printf("\n-------------------------\n");
	for (i=0;i>=top;i++){
		printf("\n%d", stack[i]);
	}
	printf("\n\n");getch();
}

int isempty(){
	return (top== -1);
}
 int isfull(){
 	return (top==SIZE - 1);
}

