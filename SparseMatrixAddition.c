#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Triplet;

// Convert a matrix to sparse triplet form
int toSparse(int matrix[10][10], int rows, int cols, Triplet sparse[]) {
    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
    return k; // number of non-zero elements
}

// Add two sparse matrices
int addSparse(Triplet A[], int sizeA, Triplet B[], int sizeB, Triplet result[]) {
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (A[i].row == B[j].row && A[i].col == B[j].col) {
            int sum = A[i].value + B[j].value;
            if (sum != 0) {
                result[k].row = A[i].row;
                result[k].col = A[i].col;
                result[k].value = sum;
                k++;
            }
            i++; j++;
        } else if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result[k++] = A[i++];
        } else {
            result[k++] = B[j++];
        }
    }

    while (i < sizeA) result[k++] = A[i++];
    while (j < sizeB) result[k++] = B[j++];

    return k; // size of result
}

// Display sparse matrix
void printSparse(Triplet sparse[], int size) {
    printf("Row\tCol\tVal\n");
    for (int i = 0; i < size; i++)
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
}

int main() {
    int rows, cols;
    int mat1[10][10], mat2[10][10];
    Triplet sparse1[100], sparse2[100], result[200];

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat1[i][j]);

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat2[i][j]);

    int size1 = toSparse(mat1, rows, cols, sparse1);
    int size2 = toSparse(mat2, rows, cols, sparse2);

    printf("\nSparse Matrix 1:\n");
    printSparse(sparse1, size1);

    printf("\nSparse Matrix 2:\n");
    printSparse(sparse2, size2);

    int resultSize = addSparse(sparse1, size1, sparse2, size2, result);

    printf("\nResultant Sparse Matrix (Addition):\n");
    printSparse(result, resultSize);

    return 0;
}