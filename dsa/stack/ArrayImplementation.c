#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    struct stack *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = malloc(s->size * sizeof(int));
}