// Q- Find the greater number of two numbers using call by reference
#include<stdio.h>

int greater(int *x, int *y)
{
    if(*x>*y)
    return *x;
    else
    return *y;
}

void main()
{
    int a,b;
    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);
    printf("Greater number: %d",greater(&a,&b));
}