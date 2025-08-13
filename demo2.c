//3.12 Q2,6,11,17`


#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* Node(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at any position
struct Node* NewPos(struct Node* head, int data, int position) {
    struct Node* newNode = Node(data);

    // Insert at beginning
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    // Create linked list with 5 nodes
    head = Node(10);
    temp = head;
    temp->next = Node(20);
    temp = temp->next;
    temp->next = Node(30);
    temp = temp->next;
    temp->next = Node(40);
    temp = temp->next;
    temp->next = Node(50);

    printf("Original Linked List:\n");
    printList(head);

    int data, position;
    printf("\nEnter data to insert: ");
    scanf("%d", &data);
    printf("Enter position to insert at: ");
    scanf("%d", &position);

    head = NewPos(head, data, position);

    printf("\nLinked List after insertion:\n");
    printList(head);

    return 0;
}
