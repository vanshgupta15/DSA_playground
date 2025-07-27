#include<stdio.h>

int factorial(int num)
{
    if(num==1||num==0)
    {
        return 1;
    }
    else
    {
        return num*factorial(num-1);
    }
}

void main()
{
    int num;
    printf("Write the number to find its factorial\n");
    scanf("%d",&num);
    printf("Answer: %d",factorial(num));
}