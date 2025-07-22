#include<stdio.h>
#include <string.h>

void main()
{
    void *arr[3];
    struct Book
    {
        char name[100];
        int prices;
        int pages;
    };

    struct Book B1;
    struct Book B2;
    struct Book B3;

    strcpy(B1.name, "DSA Book");
    B1.prices = 400;
    B1.pages = 500;

    strcpy(B2.name, "PS Book");
    B2.prices = 700;
    B2.pages = 650;

    strcpy(B3.name, "AFL Book");
    B3.prices = 969;
    B3.pages = 424;

    arr[0]=&B1;
    arr[1]=&B2;
    arr[2]=&B3;

    for(int i=0; i<3; i++)
    {
        printf("Name: %s\n",arr[i]);
        printf("Prices: %d\n",*(int*)arr[i]);
        printf("Pages: %d\n",*(int*)arr[i]);
    }
}