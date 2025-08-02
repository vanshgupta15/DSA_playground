#include<stdio.h>
void main()
{
    int *a;
    int **p;
    int t;

    t=10; //initail value
    a=&t; //address is represented by & 
    *a=t;
    p=&a;

    printf("%d\n",t);
    printf("%d\n",a);
    printf("%d\n",*a);
    printf("%d\n",p);
}