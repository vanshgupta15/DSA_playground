#include <stdio.h>

struct CQueue {
    int front;
    int rear;
    int size;
    int arr[];
};

int isFull(struct CQueue *q) {
    return (q->front == (q->rear + 1) % q->size);
}

int isEmpty(struct CQueue *q) {
    return (q->front == -1);
}

void enqueue(struct CQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = value;
}

int dequeue(struct CQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int val = q->arr[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }

    return val;
}

void display(struct CQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) %q->size;
    }
    printf("\n");
}

int main() {
    struct CQueue *q;
    q->front = -1;
    q->rear = -1;
    q->size=5;
    q->arr[q->size];

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    display(q);

    dequeue(q);
    dequeue(q);

    display(q);

    enqueue(q, 60);
    enqueue(q, 70);

    display(q);

    return 0;
}
