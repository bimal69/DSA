#include <stdio.h>

#define size 4

struct priorityqueue{
	int data[size];
	int priority[size];
	int front;
	int rear;
};
void enqueue(struct priorityqueue *pq,int data, int priority){
	if(pq->rear ==size-1){
		printf("full");return;
	}
	int i;
	for(i=pq->rear;i>=0;i--){
		if(priority > pq->priority[i]){
			pq->data[i+1] = pq->data[i];
			pq->priority[i+1] = pq->priority[i];
		}
		else{
			break;
		}
	}
	pq->data[i+1] = data;
	pq->priority[i+1] = priority;
	pq->rear++;
}
void dequeue(struct priorityqueue *pq){
	if(pq->front > pq->rear){
		printf("Empty");
		return;
	}
	printf("%d%d",pq->data[pq->front],pq->priority[pq->front]);
	pq->front++;
}
void display(struct priorityqueue *pq){
	if(pq->front>pq->rear){
		printf("Empty");
		return;
	}
	int i;
	for(i=pq->front;i<=pq->rear;i++){
		printf("%d%d",pq->data[i],pq->priority[i]);
	}
}
int main() {
    struct priorityqueue *pq;
    pq->front = 0;
    pq->rear = -1;

    int choice, value, priority;

    do {
        printf("\nPriority Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                printf("Enter the priority of the value: ");
                scanf("%d", &priority);
                enqueue(pq, value, priority);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(pq);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
