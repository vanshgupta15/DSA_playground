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
    // Shift elements to the right
    for(int i = size - 1; i >= index; i--)
    {
        A[i + 1] = A[i];
    }
    A[index] = new;
    return 0;  // Success
}

void main()
{
    int A[100] = {1, 8, 6, 47, 53, 98};  // Reserve extra space
    int size = 6;  // Actual number of elements

    printf("Old array : ");
    display(A, size);

    int new, index;
    printf("Enter the new element : ");
    scanf("%d", &new);
    printf("Enter the index : ");
    scanf("%d", &index);

    if(index >= 0 && index <= size)
    {
        int result = insert(A, size, new, index);
        if(result == 0)
        {
            size++;  // Update size after insertion
            printf("Successfully inserted. New array:\n");
            display(A, size);
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