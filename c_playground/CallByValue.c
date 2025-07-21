#include <stdio.h>

void swapByValue(int x, int y)
{
    int t;
    t = x;
    x = y;
    y = t;
    printf("%d,%d\n", x, y);
}

void main()
{
    int a = 10;
    int b = 20;
    swapByValue(a, b);
    printf("%d,%d\n", a, b);
}
