#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;

    for(int i = 1; i <= 100; i++)
    {
        x += i;
    }

    printf("%d", x);

    return 0;
}      