#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int Book_Id;
    char Title[50];
    char Borrower_Name[50];
    struct node *next;
};

void bookBorrow(struct node *ptr);
struct node* returnBook(struct node* head);
void display(struct node *ptr);
struct node* reversal(struct node *ptr);
void reverse(struct node *ptr);

void main()
{
    int choice;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->Book_Id=0;
    ptr->Title[0]='\0';
    ptr->Borrower_Name[0]='\0';
    ptr->next=NULL;
    while(1)
    {
        printf("Choose from the option:\n1.Borrow a book\n2.Return a book\n3.Display all the borrowed book\n4.See the recent borrowed book\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                bookBorrow(ptr);
                break;
            }
            case 2:
            {
                ptr=returnBook(ptr);
                break;
            }
            case 3:
            {
                display(ptr);
                break;
            }
            case 4:
            {
                reverse(ptr);
                break;
            }
            case 5:
            {
                exit(0);
            }
            default:
            {
                printf("Wrong option chosen\n");
            }
        }
    }
}

void reverse(struct node *ptr)
{
    struct node *rev=reversal(ptr);
    display(rev);
}

void bookBorrow(struct node *ptr)
{
    int bookid; char title[50]; char borrowerName[50];
    printf("Enter book id: ");
    scanf("%d",&bookid);
    printf("Enter book title: ");
    scanf("%49s",title);
    printf("Enter your name: ");
    scanf("%49s",borrowerName);
    if(ptr==NULL)
    {
        return;
    }
    if(ptr->Book_Id==0 && ptr->Title[0]=='\0' && ptr->Borrower_Name[0]=='\0')
    {
        ptr->Book_Id=bookid;
        strcpy(ptr->Title,title);
        strcpy(ptr->Borrower_Name,borrowerName);
        ptr->next=NULL;
    }
    else
    {
        struct node *temp=ptr;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        struct node *newNode=(struct node*)malloc(sizeof(struct node));
        newNode->Book_Id=bookid;
        strcpy(newNode->Title,title);
        strcpy(newNode->Borrower_Name,borrowerName);
        newNode->next=NULL;
        temp->next=newNode;
    }
}

struct node* returnBook(struct node* head)
{
    int bookid;
    printf("Enter the book id to return: ");
    scanf("%d",&bookid);
    struct node *temp=head;
    struct node *prev=NULL;
    if(temp!=NULL && temp->Book_Id==bookid)
    {
        head=temp->next;
        free(temp);
        printf("Book with ID %d has been returned.\n",bookid);
        return head;
    }
    while(temp!=NULL && temp->Book_Id!=bookid)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Book with ID %d not found.\n",bookid);
        return head;
    }
    prev->next=temp->next;
    free(temp);
    printf("Book with ID %d has been returned.\n",bookid);
    return head;
}

void display(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%s\n",ptr->Title);
        ptr=ptr->next;
    }
}

struct node* reversal(struct node *ptr)
{
    struct node *prev=NULL,*current=ptr,*next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
    }
    return prev;
}