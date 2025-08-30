#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void insertionAtPosition(struct node *ptr, int data,int pos)
{
    struct node *temp= malloc(sizeof(struct node));
    for(int i=0;i<pos-1; i++)
    {
        ptr=ptr->next;
    }
    temp->prev=ptr;
    temp->data=data;
    temp->next=ptr->next;
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
    int newData,index;
    printf("Enter the new data to be entered at the beginning: ");
    scanf("%d",&newData);
    printf("Enter the index you want to insert at: ");
    scanf("%d",&index);
    insertionAtPosition(head,newData,index);
    display(head);
}