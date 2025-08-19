#include<stdio.h>

void display(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void delete(int arr[], int size, int index)
{
    for(int i=index; i<size-1; i++)
    {
        arr[i]=arr[i+1];
    }
}

void main()
{
    int arr[10]={2,5,8,15,26,39};
    int size= sizeof(arr)/sizeof(arr[0]);
    printf("Old array:\n");
    display(arr,size);
    int index;
    printf("Enter the index of the element to be deleted: ");
    scanf("%d",&index);
    delete(arr,size,index);
    size--;
    display(arr,size);
}