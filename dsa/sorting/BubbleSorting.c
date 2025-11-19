#include<stdio.h>

void bubbleSort(int arr[], int n) 
{
    int i, j,temp;

    for (i = 0; i<n-1; i++)
    {
        int flag=0;
        for (j=0; j<n-i-1; j++) 
        {
            if (arr[j+1] < arr[j]) 
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}

void main() 
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("Sorted array: ");
    for (int i=0; i<n; i++) 
    {
        printf("%d ", arr[i]);
    }
}