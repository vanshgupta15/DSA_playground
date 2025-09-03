#include<stdio.h>

void main()
{
    int n;
    printf("Enter the highest power of the polynomial: ");
    scanf("%d",&n);
    int A[n+1];
    for(int i=0; i<=n;i++)
    {
        printf("Enter value of x^%d: ",i);
        scanf("%d",&A[i]);
    }
    //printing the polynomial
    for(int j=n;j>=0;j--)
    {
        if(A[j]!=0)
        {
            printf("%dx^%d",A[j],j);
            if(j>0)
            {
                printf("+");
            }
        }
    }
    //printing the array
    printf("[");
    for(int i=0; i<=n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("]");
}