#include <stdio.h>

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int A[], int size, int new, int index)
{
    for(int i = size-1 ; i >= index; i--)
    {
        A[i + 1] = A[i];
    }
    A[index] = new;
    return 0; 
}

void main()
{
    int arr[10] = {1, 8, 6, 47, 53, 98}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Old array : ");
    display(arr, size);

    int new, index;
    printf("Enter the new element : ");
    scanf("%d", &new);
    printf("Enter the index : ");
    scanf("%d", &index);

    if(index >= 0 && index <= size)
    {
        int result = insert(arr, size, new, index);
        if(result == 0)
        {
            size++;  
            printf("Successfully inserted. New array:\n");
            display(arr, size);
        }
        else
        {
            printf("FAILED\n");
        }
    }
    else
    {
        printf("FAILED: Invalid index\n");
    }
} 