#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE], front=-1, rear=-1;
void enqueue(int k){
	if (isfull()){
		printf("Queue is full");getch();
		return;
	}
	if(isempty()){
		rear=0;front=0;
	}
	else{
		rear++;
	}
	queue[rear]=k;
}
int dequeue(){
	int res;
	if(isempty()){
		return -1;
	}
	res=queue[front];
	if(front==rear){
		front==-1;
		rear==0;
	}
	else{
		front++;
	}
	return res;
}
int peek(){
	if(front==-1 && rear==-1){
		printf("\nQueue is empty");
		return -1;
	}
	return queue[front];
}

void list(){
 	int i;
 	if(isempty()){
	 
 		printf("\nQueue is empty");getch();return;
	 }
	 for(i=0;i<=rear;i++){
	 	printf("%d\t",queue[i]);
	 }
}

void main(){
	char choice;
	int k,res;
	do{
		system("cls");
		printf("\nQueue bases on Array!\n");
		printf("\n---------------------\n");
		printf("1.Enqueue\t\t\n");
		printf("2.Dequeue\t\t\n");
		printf("3.List\t\t\n");
		printf("4.Peek\t\t\n");
		printf("5.EXit\t\t\n");
		printf("\n\nWhich operation?");
		scanf("%c",&choice);
		
		switch(choice){
			case '1': printf("\nEnter a data number:\n");scanf("%d",&k); enqueue(k);break;
			case '2': res=dequeue();
					if(res==-1){
						printf("\n\nQueue is empty");
					}
					else{
						printf("\n\n%d is dequeued from queue!\n\n",k);
					}
					break;
			case '3': list();break;
			
			case '4': peek();break;
			case '5': printf("\n\nThanks");
			default : printf("\nInvalid choice.");
		}
	}while (choice!='4');
	
}
int isfull() {
    return ((rear + 1) % SIZE == front);
}

int isempty() {
    return (front == -1 && rear == -1) ? 1 : 0;
}




