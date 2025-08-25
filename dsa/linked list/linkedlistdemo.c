#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void main()
{
    //declaring the nodes
    struct node *head;
    struct node *second;
    struct node *third; 
    
    //allocating memory in the heap
    head= (struct node*)malloc(sizeof(struct node));
    second= (struct node*)malloc(sizeof(struct node));
    third= (struct node*)malloc(sizeof(struct node));

    //linking head and second node
    head->data=10;
    head->next=second;
    //linking second and third node
    second->data=20;
    second->next=third;
    //eliminating third 
    third->data=30;
    third->next=NULL;
    
    
}