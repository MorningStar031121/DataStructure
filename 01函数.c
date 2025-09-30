#include <stdio.h>

void increment(int* x)
{
    (*x)++;
}

int main()
{
    int a = 0;
    printf("调用之前a的值:%d\n", a);
    increment(&a);
    printf("调用之后a的值:%d\n", a);
    
    return 0;
}