#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insertion(struct node* ptr, int data, int pos)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    for(int i=0; i<pos-1; i++)
    {
        ptr=ptr->next;
    }
    newNode->data=data;
    newNode->next=ptr->next;
    ptr->next=newNode;
}

void display(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
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
        newNode->next=NULL;
        if(head==NULL)
        {
            head=newNode;
            current=newNode;
        }
        else
        {
            current->next=newNode;
            current=newNode;
        }
    }
    int pos,newData;
    printf("Enter the new data to be inserted: ");
    scanf("%d",&newData);
    printf("Enter the index where you want to insert the new node : ");
    scanf("%d",&pos);
    insertion(head,newData,pos);
    display(head);
}