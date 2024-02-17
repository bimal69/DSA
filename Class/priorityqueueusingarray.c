#include <stdio.h>

#define MAX_SIZE 4

struct PriorityQueue {
    int data[MAX_SIZE];
    int priority[MAX_SIZE];
    int front;
    int rear;
};

void enqueue(struct PriorityQueue *pq, int value, int priority) {
    if (pq->rear == MAX_SIZE - 1) {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }

    int i;
    for (i = pq->rear; i >= 0; i--) {
        if (priority > pq->priority[i]) {
            pq->data[i + 1] = pq->data[i];
            pq->priority[i + 1] = pq->priority[i];
        } else {
            break;
        }
    }

    pq->data[i + 1] = value;
    pq->priority[i + 1] = priority;

    pq->rear++;
    printf("Enqueued %d with priority %d\n", value, priority);
}

void dequeue(struct PriorityQueue *pq) {
    if (pq->front > pq->rear) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }

    printf("Dequeued %d with priority %d\n", pq->data[pq->front], pq->priority[pq->front]);
    pq->front++;
}

void display(struct PriorityQueue pq) {
    if (pq.front > pq.rear) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue:\n");
    printf("Front -> ");
    int i;
    for (i = pq.front; i <= pq.rear; i++) {
        printf("[%d, %d] -> ", pq.data[i], pq.priority[i]);
    }
    printf("Rear\n");
}

int main() {
    struct PriorityQueue pq;
    pq.front = 0;
    pq.rear = -1;

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
                enqueue(&pq, value, priority);
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

