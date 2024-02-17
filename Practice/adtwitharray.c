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
	stack = (int *)malloc(size * sizeof(int));
	do{
		printf("\nStack Based on Array\n");
	printf("1. PUSH\n");
	printf("2. POP\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Which operation?\t");
	scanf("%d",&choice);
	
	switch(choice){
		case 1: printf("Enter the number: ");scanf("%d",k);push(k);break;
		case 2: pop();break;
		case 3: display();break;
		case 4: printf("Bye/Bye");
				return 0;free(stack);break;
		default: printf("You have to choose one option");break;
	}
	}while(1);
	free(stack);
	return 0;
	
}
void push(int k){
	
	if(isfull()){
		printf("Stack is full\n");
		return;
	}
	stack[++top]=k;
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
		for(i=0;i<5;i++){
			printf("%d",stack[i]);
		}
	}
}
int isfull()
{
    return (top == size - 1);
}






