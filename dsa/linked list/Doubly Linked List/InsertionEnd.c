#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void insertionEnd(struct node *ptr, int data)
{
    struct node *temp= malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    temp->prev=ptr;
    ptr->next=temp;
}

void display(struct node *ptr)
{
    printf("NULL<->");
    while(ptr!=NULL)
    {
        printf("%d<->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

void main()
{
    int n;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d",&n);
    struct node *head= NULL, *newNode= NULL, *current= NULL;
    for(int i=0; i<n; i++)
    {
        int data;
        printf("Enter data for %d node: ",i+1);
        scanf("%d",&data);
        newNode= (struct node*)malloc(sizeof(struct node));
        newNode->data=data;
        newNode->prev=NULL;
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            current=newNode;
        }
        else
        {
            current->next=newNode;
            newNode->prev=current;
            current=newNode;
        }
    }
    int newData;
    printf("Enter the new data to be entered at the beginning: ");
    scanf("%d",&newData);
    insertionEnd(head,newData);
    display(head);
}