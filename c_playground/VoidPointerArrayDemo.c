#include<stdio.h>
void main()
{
    void *arr[3];
    int a=10;
    float b=45.56;

    struct N
    {
        int i;
        float j;
    };

    struct N n1;
    n1.i=100;
    n1.j=15.25;

    arr[0]=&a;
    arr[1]=&b;
    arr[2]=&n1;

    printf("%d\n",*(int*)arr[0]);
    printf("%0.2f\n",*(float*)arr[1]);
    
    struct N *ptr = (struct N *)arr[2];
    printf("Struct i: %d\n", ptr->i);
    printf("Struct j: %f\n", ptr->j);
}