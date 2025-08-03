#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *ptr;
    int n;

    //malloc
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        printf("Enter the value at %d position: \n",i);
        scanf("%d",&ptr[i]);
    }
    for(int i=0; i<n; i++)
    {
        printf("Value at %d position: %d\n",i,ptr[i]);
    }

    //calloc
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    ptr=(int *)calloc(n,sizeof(int));
    for(int i=0; i<n; i++)
    {
        printf("Enter the value at %d position: \n",i);
        scanf("%d",&ptr[i]);
    }
    for(int i=0; i<n; i++)
    {
        printf("Value at %d position: %d\n",i,ptr[i]);
    }

    //realloc
    printf("Enter the new size of the array: \n");
    scanf("%d",&n);
    ptr=(int *)realloc(ptr, n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        printf("Enter the value at %d position: \n",i);
        scanf("%d",&ptr[i]);
    }
    for(int i=0; i<n; i++)
    {
        printf("New Value at %d position: %d\n",i,ptr[i]);
    }

    //free
    free(ptr);
    for(int i=0; i<n; i++)
    {
        printf("New Value at %d position: %d\n",i,ptr[i]);
    }
}