//C implementation of priority queue based on array

#include <stdio.h>
#include <conio.h>
#include <limits.h>
struct node{
	int val;
	int priority;
};

int enqueue(struct node);
struct node dequeue();
void  list();
int peek();

struct node pqueue[100];
int SIZE = -1;

void main(){
	struct node p, p1, p2, p3,p4;
	p.val = 13; p.priority = 4;
	enqueue(p);
	
	p1.val = 46; p1.priority = 2;
	enqueue(p1);
	p2.val = 88; p2.priority = 13;
	enqueue(p2);
	p3.val = 91; p3.priority = 6;
	enqueue(p3);
	p4.val = 149; p4.priority = 34;
	enqueue(p4);
	
	printf("\nPqueue before dequeue\n");
	list();
	printf("\n\n\n");
	printf("\nPqueue after dequeue\n");

	dequeue();
	
	list();
	

}
int enqueue(struct node n){
	
	if(SIZE==99){
		printf("\nQueue is full");getch();return;
	}
	SIZE++;
	pqueue[SIZE] = n;
			
}
struct node dequeue(){
	int maxp;
	struct node q;
	if (SIZE == -1){
			printf("\nPriority Queue is empty!");getch();return;
	}
	int i;
	maxp = peek();
	for (i=maxp;i<=SIZE;i++){
		pqueue[i]=pqueue[i+1];
	}
	SIZE--;
	return q;
}

int peek(){
	int maxp = 0;
	int i;
	if (SIZE == -1){
		printf("\nPriority Queue is empty!");getch();return;
	}
	for(i=0;i<=SIZE;i++){
		if(maxp<pqueue[i].priority){
			maxp = i;
		}	
	}
	return maxp;	
}
void list(){
	int i;
	if(SIZE==-1){
		printf("\nPriority Queue is empty");getch();return;
	}
	for(i=0;i<=SIZE;i++){
		printf("\nVal:%d\t\t Prioriity:%d\n",pqueue[i].val,pqueue[i].priority);
	}
}
