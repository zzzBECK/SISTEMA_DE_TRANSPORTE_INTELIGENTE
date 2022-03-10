#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL,"portuguese");
    int i, j, k = 0;
    int entrada[3];
    double final[3];
    int lista1[] = {30, 10, 100, 45, 20, 150, 60, 35, 250};
    int valores[] = {50, 75, 100};
    double exed[] = {0.8, 0.5, 0.25, 0.9, 0.6, 0.2, 1.0, 0.75, 0.30};

    scanf("%d %d %d", &entrada[0], &entrada[1], &entrada[2]);

    for (i = 0; i < 3; i++)
    {
        float excesso = 0;
        int mult[] = {0, 0, 0};

        for (j = 0; j < 3; j++)
        {
            if (entrada[j] >= lista1[j + k])
                mult[j] = entrada[j] - lista1[j + k];

            excesso += mult[j] * exed[j + k]; 
        }

        final[i] = valores[i] + excesso;

        k += 3;
    }

    if (final[0] <= final[1] && final[0] <= final[2])
        printf("Plano Alfa: R$ %.2lf\n", final[0]);

    else if (final[1] <= final[0] && final[1] <= final[2])
        printf("Plano Beta: R$ %.2lf\n", final[1]);

    else 
        printf("Plano Delta: R$ %.2lf\n", final[2]);


    return 0;
}