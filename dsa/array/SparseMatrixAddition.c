#include <stdio.h>
#include <stdlib.h>

// Function to convert matrix → sparse (triplet)
int toSparse(int rows, int cols, int mat[rows][cols], int sparse[][3]) {
    int k = 0;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    return k; // number of non-zero elements
}

// Function to add two sparse matrices using simple if-else (row → col check)
int addSparse(int s1[][3], int s2[][3], int m, int n, int s3[][3]) {
    int i=0, j=0, k=0;

    while (i<m && j<n) {
        if (s1[i][0] == s2[j][0]) { // same row
            if (s1[i][1] == s2[j][1]) {  // same col → add values
                int sum = s1[i][2] + s2[j][2];
                if (sum != 0) {
                    s3[k][0] = s1[i][0];
                    s3[k][1] = s1[i][1];
                    s3[k][2] = sum;
                    k++;
                }
                i++; j++;
            } 
            else if (s1[i][1] < s2[j][1]) { // s1 col smaller
                s3[k][0] = s1[i][0];
                s3[k][1] = s1[i][1];
                s3[k][2] = s1[i][2];
                i++; k++;
            } 
            else { // s2 col smaller
                s3[k][0] = s2[j][0];
                s3[k][1] = s2[j][1];
                s3[k][2] = s2[j][2];
                j++; k++;
            }
        } 
        else if (s1[i][0] < s2[j][0]) { // s1 row smaller
            s3[k][0] = s1[i][0];
            s3[k][1] = s1[i][1];
            s3[k][2] = s1[i][2];
            i++; k++;
        } 
        else { // s2 row smaller
            s3[k][0] = s2[j][0];
            s3[k][1] = s2[j][1];
            s3[k][2] = s2[j][2];
            j++; k++;
        }
    }

    // Copy remaining elements
    while (i<m) {
        s3[k][0] = s1[i][0];
        s3[k][1] = s1[i][1];
        s3[k][2] = s1[i][2];
        i++; k++;
    }
    while (j<n) {
        s3[k][0] = s2[j][0];
        s3[k][1] = s2[j][1];
        s3[k][2] = s2[j][2];
        j++; k++;
    }

    return k; // non-zero count of result
}

// Utility: print sparse matrix
void printSparse(int count, int s[][3], char name) {
    printf("\nSparse Matrix %c (row col val):\n", name);
    for (int i=0; i<count; i++) {
        printf("%3d %3d %3d\n", s[i][0], s[i][1], s[i][2]);
    }
}

int main() {
    int r, c;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);

    int A[r][c], B[r][c];

    // Input matrix A
    printf("\nEnter elements of Matrix A (%dx%d):\n", r, c);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Input matrix B
    printf("\nEnter elements of Matrix B (%dx%d):\n", r, c);
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Convert to sparse
    int s1[r*c][3], s2[r*c][3], s3[r*c*2][3];
    int countA = toSparse(r, c, A, s1);
    int countB = toSparse(r, c, B, s2);

    // Add sparse
    int countC = addSparse(s1, s2, countA, countB, s3);

    // Print sparse matrices
    printSparse(countA, s1, 'A');
    printSparse(countB, s2, 'B');
    printSparse(countC, s3, 'C'); // Result
}
