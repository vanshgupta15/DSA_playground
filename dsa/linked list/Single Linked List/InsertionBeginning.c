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

    //insertion at beginning
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    temp=head;
    struct node *addedNode= malloc(sizeof(struct node));
    int newData;
    printf("Enter data for new node:");
    scanf("%d",&newData);
    addedNode->data=newData;
    addedNode->next=temp;
    head=addedNode;
    printing(head);
}