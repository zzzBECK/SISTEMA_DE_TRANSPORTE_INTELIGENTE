#include <stdio.h>
#include <math.h>

struct parada3                // variaveis para as paradas
{
    int id;
    float x, y;
};

void paradaProxima()
{
    FILE *file, *tempfile;
    int aux, k = 0, posicao, ID, id[100];
    float X, Y, latitude[100], longitude[100], distancia, menor = 99999;
    struct parada3 p;

    file = fopen("paradas.txt", "r");

    if (file != NULL)
    {
        printf("DIGITE SUA LOCALIZAO ATUAL! (com 3 casas decimais)\n\n");
        do
        {
            fflush(stdin);
            printf("Latitude: ");
            aux = scanf("%f", &p.x);

            if (aux == 0)
                printf("Valor invalido, digite novamente\n");

        } while (aux == 0);                                                 // verifica se é um numero


        do
        {
            fflush(stdin);
            printf("Longitude: ");
            aux = scanf("%f", &p.y);

            if (aux == 0)
                printf("Valor invalido, digite novamente\n");

        } while (aux == 0); 


        while (fscanf(file, "%d;%f;%f", &id[k], &latitude[k], &longitude[k]) != EOF)
        {
            k++;
        }


        for (int i = 0; i < k; i++)
        {
            distancia = sqrt(((latitude[i] - p.x)*(latitude[i] - p.x))+((longitude[i]-p.y)*(longitude[i]-p.y)));

            if (distancia < menor)
            {
                menor = distancia;
                X = latitude[i];
                Y = longitude[i];
                ID = id[i];
            }
                
        }

        printf("\nPARADA MAIS PROXIMA: %d\n\nPosicao da parada: Latitude: %.3f Longitude: %.3f\n", ID, X, Y);

    }
    
}