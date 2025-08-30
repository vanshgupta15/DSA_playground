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

void deletion(struct node *ptr,int pos)
{
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    for(int i=0; i<pos-1; i++)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
}
void main()
{
    int n,pos;
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
    printf("Enter the index of the node to be deleted : ");
    scanf("%d",&pos);
    deletion(head,pos);
    printing(head);
}