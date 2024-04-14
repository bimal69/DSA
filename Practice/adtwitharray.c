#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 5

int *stack;
void push();
void pop();
void display();
int top = -1;

  
int main(){
	int res,k;
	int choice;
	
	do{
		printf("\nStack Based on Array\n");
	printf("1. PUSH\n");
	printf("2. POP\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Which operation?\t");
	scanf("%d",&choice);
	
	switch(choice){
		case 1: push();break;
		case 2: pop();break;
		case 3: display();break;
		case 4: printf("Bye/Bye");
				free(stack);break;return 0;
		default: printf("You have to choose one option");break;
	}
	}while(1);
	free(stack);
	return 0;
	
}
void createnewstack(){
	stack = (int *)malloc(size * sizeof(int));
}
void push(){
	createnewstack();
	int k;
	printf("Enter the number: ");
	scanf("%d",&k);
	if(isfull()){
		printf("Stack is full\n");
		return;
	}
	else{
		stack[++top]=k;
	}
	
}
void pop(){
	if(top==-1){
		printf("Stack is empty");
		
	}
	else{
		stack[top--];
	}
}

void display(){
	int i;
	if(top==-1){
		printf("Stack is empty");
	}
	else {
		for(i=0;i<=top;i++){
			printf("%d",stack[i]);
		}
	}
}
int isfull()
{
    return (top == size - 1);
}






