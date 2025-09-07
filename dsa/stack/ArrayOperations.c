#include<stdio.h>
#include<stdlib.h>

struct stack 
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, int value)
{
    if(isFull(ptr))
    {
        printf("The stack is full\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}

void pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
    }
    else
    {
        int temp=ptr->arr[ptr->top];
        ptr->top--;
        printf("Popped value : %d\n",temp);
    }    
}

void display(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack is empty!\n");
    }
    else
    {
        printf("Stack elements (top to bottom):\n");
        printf(" ---\n");
        for(int i = ptr->top; i >= 0; i--)
        {
            printf("|%d|\n", ptr->arr[i]);
            printf(" ---\n");
        }
    }
}

void main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));

    int i=1;
    while(i==1)
    {
        int choice;
        printf("Choose a option:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                int value;
                printf("Enter the value to be pushed:");
                scanf("%d",&value);
                push(s,value);
                break;
            }
            case 2:
            {
                pop(s);
                break;
            }
            case 3:
            {
                display(s);
                break;
            }
            case 4:
            {
                i=0;
            }
        }
    }
}