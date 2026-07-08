#include <stdio.h>

void B(int n);

void A(int n)
{
    if(n > 0)
    {
        printf("A ");
        B(n - 1);
    }
}

void B(int n)
{
    if(n > 1)
    {
        printf("B ");
        A(n / 2);
    }
}

int main()
{
    A(20);
}