#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front;
    int rear;
    int size;
    int arr[];
};

// Check if queue is full
int isFull(struct Queue *q) {
    return q->rear == (q->size)- 1;
}

// Check if queue is empty
int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

// Enqueue operation
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is FULL!\n");
        return;
    }

    if (q->front == -1)  // inserting first element
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = value;
    printf("%d inserted into queue\n", value);
}

// Dequeue operation
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Deleted element: %d\n", q->arr[q->front]);
    q->front++;
}

// Peek (front element)
void peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Front element: %d\n", q->arr[q->front]);
}

// Display the queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {

    struct Queue *q;
    q->front=-1;
    q->rear=-1;
    q->size=5;
    q->arr[q->size];

    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                peek(q);
                break;

            case 4:
                display(q);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
