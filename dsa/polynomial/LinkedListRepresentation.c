#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int pow;
    struct node *next;
};

// Create new node
struct node* createNode(int coeff, int pow) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

// Insert term at end
void insert(struct node** poly, int coeff, int pow) {
    struct node* newNode = createNode(coeff, pow);

    if (*poly == NULL) {
        *poly = newNode;
        return;
    }

    struct node* temp = *poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display polynomial
void display(struct node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL && poly->coeff >= 0)
            printf(" + ");
        else if (poly != NULL)
            printf(" ");
    }
    printf("\n");
}

int main() {
    struct node* poly = NULL;

    insert(&poly, 5, 3);
    insert(&poly, 4, 2);
    insert(&poly, -2, 1);
    insert(&poly, 7, 0);

    printf("Polynomial: ");
    display(poly);

    return 0;
}
