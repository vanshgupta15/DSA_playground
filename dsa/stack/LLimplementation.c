#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void traversal(struct node *ptr) 
{
    if (ptr == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    while (ptr != NULL) 
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next; 
    }
    printf("NULL\n");
}

int isEmpty(struct node* ptr) 
{
    return (ptr == NULL);
}

void push(struct node **top, int data) 
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;   // update top
}

void pop(struct node **top) 
{
    if (isEmpty(*top)) 
    {
        printf("Underflow condition\n");
    } else {
        struct node *n = *top;
        int data = n->data;
        *top = (*top)->next;
        free(n);
        printf("Popped data: %d\n", data);
    }
}

int main() 
{
    struct node *top = NULL;  // start with empty stack

    int i = 1;
    while (i == 1)
    {
        int choice;
        printf("\nChoose an option:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: 
            {
                int data;
                printf("Enter data: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            }
            case 2:
                pop(&top);
                break;
            case 3:
                traversal(top);
                break;
            case 4:
                i = 0;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
