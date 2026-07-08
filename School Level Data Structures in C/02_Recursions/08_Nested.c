#include <stdio.h>

int fun(int n)
{
    if(n > 100)
        return n - 10;

    return fun(fun(n + 11));
}

int main()
{
    printf("%d", fun(95));
}

// fun(
//     fun(...)
//    )
// The inner fun() must finish first, then its result becomes the argument of the outer fun().