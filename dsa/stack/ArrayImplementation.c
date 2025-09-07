#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
}

void isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Stack is not full\n");
    }
}

void main()
{
    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    isEmpty(s);
    isFull(s);
}