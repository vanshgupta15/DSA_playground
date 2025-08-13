#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* Node(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert at beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = Node(data);
    newNode->next = head;
    head = newNode;
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

    // Insert at beginning
    head = insertAtBeginning(head, 5);

    printf("\nAfter Inserting at Beginning:\n");
    printList(head);

    return 0;
}
