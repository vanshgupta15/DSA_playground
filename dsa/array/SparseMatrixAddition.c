/*Perform sparse matrix addition.
a) input two matrix
b) create their triplet/compressed form
c) using the compressed/triplet form perform addition*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int countA=0;
    printf("Enter the size of matrix ");
    //MatrixA
    int A[3][3];
    for(int i=1; i<4; i++)
    {
        for(int j=1;j<4;j++)
        {
            printf("Enter the value for [%d,%d] of matrix A: ",i,j);
            scanf("%d",&A[i][j]);
            if(A[i][j]!=0) countA++;
        }
    }

    int aCompress[3][countA];
    int k=0;
    for(int i=1; i<4; i++)
    {
        for(int j=1; j<4; j++)
        {
            
        }
    }

    //MatrixB
    int B[3][3];
    for(int i=1; i<4; i++)
    {
        for(int j=1;j<4;j++)
        {
            printf("Enter the value for [%d,%d] of matrix B: ",i,j);
            scanf("%d",&B[i][j]);
        }
    }
}