#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr= ptr->next;
    }
    printf("NULL");
}

//Function to insert at beginning (same logic as your code)
struct node* insertionBeginning(struct node *head)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;

    struct node *addedNode = (struct node*)malloc(sizeof(struct node));
    int newData;
    printf("Enter data for new node: ");
    scanf("%d", &newData);
    addedNode->data = newData;
    addedNode->next = temp;
    head = addedNode;

    return head;  // returning updated head
}

void main()
{
    int n;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d",&n);

    struct node *head = NULL, *newNode = NULL, *current = NULL;
    for(int i=0; i<n; i++)
    {
        int data;
        printf("Enter data for %d node: ",i+1);
        scanf("%d",&data);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            current = newNode;
        }
    }

    //Call function to insert at beginning
    head = insertionBeginning(head);

    //Print updated linked list
    display(head);
}
