#include <stdio.h>

int main ()
{
    double n, sum;

    scanf("%lf", &n);

    if (n > 4500)
    {
        sum = (n - 4500) * 0.28 + (4500 - 3000.01) * 0.18 + (3000 - 2000.01) * 0.08;
    }
    else if (n > 3000 && n <= 4500)
    {
        sum = (n - 3000) * 0.18 + (3000 - 2000.01) * 0.08;
    }
    else if (n > 2000 && n <= 3000)
    {
        sum = (n - 2000) * 0.08;
    }
    else if (n <= 2000)
        sum = 0;
    
    if (sum == 0)
        printf("Isento\n");
    else
        printf("R$ %.2f\n", sum);
    return 0;
}