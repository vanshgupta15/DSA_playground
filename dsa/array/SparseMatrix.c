#include<stdio.h>
#include<stdlib.h>

void main()
{
    int x,y;
    printf("Enter number of rows in the matrix: ");
    scanf("%d",&x);
    printf("Enter number of columns in the matrix: ");
    scanf("%d",&y);

    int A[x][y];  // original matrix

    // Input matrix
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            printf("Enter data for A[%d][%d]: ", i, j);
            scanf("%d",&A[i][j]);
        }
    }

    // Printing original matrix
    printf("\nOriginal Matrix:\n");
    for(int i=0; i<x; i++)    
    {
        for(int j=0; j<y; j++)
        {
            printf("%3d ",A[i][j]);
        }
        printf("\n");
    }

    // Counting non-zero elements
    int count = 0;
    for (int i = 0; i <x; i++) 
    {
        for (int j = 0; j < y; j++) 
        {
            if (A[i][j] != 0) 
            {
                count++;
            }
        }
    }

    // Sparse matrix formation (row, col, value)
    int sparse[count][3];
    int k=0;
    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++) 
        {
            if (A[i][j] != 0) 
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = A[i][j];
                k++;
            }
        }
    }

    // Printing sparse matrix
    printf("\nSparse Matrix \nRow Col Val\n");
    for(int i=0; i<count; i++)    
    {
        for(int j=0; j<3; j++)
        {
            printf("%3d ",sparse[i][j]);
        }
        printf("\n");
    }
}
