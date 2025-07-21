#include<stdio.h>
void main()
{
    int a=10;
    char b='x';
    void *ptr= &a;
    printf("%d\n",ptr);
    printf("%d\n",&a);
    ptr= &b;
    printf("%d\n",ptr);
}