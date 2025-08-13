#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int val;
} Term;

void readSparse(Term s[]) {
    int i;
    printf("Enter number of rows, columns, and non-zero elements: ");
    scanf("%d%d%d", &s[0].row, &s[0].col, &s[0].val);

    printf("Enter row, column, and value for each non-zero element:\n");
    for (i = 1; i <= s[0].val; i++) {
        scanf("%d%d%d", &s[i].row, &s[i].col, &s[i].val);
    }
}

void displaySparse(Term s[]) {
    int i;
    printf("\nRow\tCol\tValue\n");
    for (i = 0; i <= s[0].val; i++) {
        printf("%d\t%d\t%d\n", s[i].row, s[i].col, s[i].val);
    }
}

// Sort sparse matrix elements by row, then column
void sortSparse(Term s[]) {
    int i, j;
    for (i = 1; i <= s[0].val; i++) {
        for (j = i + 1; j <= s[0].val; j++) {
            if (s[i].row > s[j].row || 
               (s[i].row == s[j].row && s[i].col > s[j].col)) {
                Term temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void addSparse(Term a[], Term b[], Term c[]) {
    int i = 1, j = 1, k = 1;

    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("\nMatrix dimensions do not match. Cannot add.\n");
        c[0].val = 0;
        return;
    }

    c[0].row = a[0].row;
    c[0].col = a[0].col;

    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row < b[j].row || 
            (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
        } 
        else if (b[j].row < a[i].row || 
                (b[j].row == a[i].row && b[j].col < a[i].col)) {
            c[k++] = b[j++];
        } 
        else { // same row and col
            c[k] = a[i];
            c[k++].val = a[i++].val + b[j++].val;
        }
    }

    while (i <= a[0].val) c[k++] = a[i++];
    while (j <= b[0].val) c[k++] = b[j++];

    c[0].val = k - 1;
}

int main() {
    Term a[MAX], b[MAX], c[MAX];

    printf("Enter first sparse matrix:\n");
    readSparse(a);

    printf("\nEnter second sparse matrix:\n");
    readSparse(b);

    // Sort both matrices before addition
    sortSparse(a);
    sortSparse(b);

    addSparse(a, b, c);

    printf("\nFirst matrix:");
    displaySparse(a);

    printf("\nSecond matrix:");
    displaySparse(b);

    printf("\nSum matrix:");
    displaySparse(c);

    return 0;
}
