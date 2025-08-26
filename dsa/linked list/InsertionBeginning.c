#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void printing(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr= ptr->next;
    }
    printf("NULL");
}

void main()
{
    //declaring the nodes and memory allocation
    struct node *head= (struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node)); 

    //linking the nodes
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=NULL;

    //insertion at beginning
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    temp=head;
    struct node *newNode= malloc(sizeof(struct node));
    newNode->data=5;
    newNode->next=temp;
    head=newNode;
    printing(head);
}