#include<stdio.h>
void main()
{
    void *arr[2];
    int a=10;
    float b=10.67;
    arr[0]=&a;
    arr[1]=&b;
    printf("%d\n", *(int *)arr[0]);
    printf("%f\n", *(float *)arr[1]);
}  