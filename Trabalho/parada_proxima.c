#include <stdio.h>
#include <math.h>

void paradaProxima()
{
    FILE *file, *tempfile;

    int aux, k = 0, ID, id[TAM_MAX];

    float X, Y, latitude[TAM_MAX], longitude[TAM_MAX], menor_distancia, menor = 99999, arredondado;

    struct parada p;
    
    file = fopen("paradas.txt", "r");

    //verifica se o arquivo existe
    if (file != NULL)
    {
        printf("DIGITE SUA LOCALIZAO ATUAL!\n\n");
        do
        {
            fflush(stdin);
            printf("Latitude: ");
            aux = scanf("%f", &arredondado);

            p.x = floor(arredondado * 1000.0f) / 1000.0f;
            
            if (aux == 0)
                printf("Valor invalido, digite novamente\n");

        } while (aux == 0);                                                 // verifica se é um numero
        //loop para pegar a latitude atual do usuario

        do
        {
            fflush(stdin);
            printf("Longitude: ");
            aux = scanf("%f", &arredondado);

            p.y = floor(arredondado * 1000.0f) / 1000.0f;

            if (aux == 0)
                printf("Valor invalido, digite novamente\n");

        } while (aux == 0); 
        //loop para pegar a longitude atual do usuario
    
        // armazenamento dos valores contidos no arquivo paradas.txt em vetores separados
        while (fscanf(file, "%d;%f;%f", &id[k], &latitude[k], &longitude[k]) != EOF)
        {
            k++;
        }

        //verificação da menor distancia entre o usuario e as paradas cadastradas
        for (int i = 0; i < k; i++)
        {
            menor_distancia = sqrt(((latitude[i] - p.x)*(latitude[i] - p.x)) + ((longitude[i] - p.y) * (longitude[i] - p.y)));

            if (menor_distancia < menor)
            {
                menor = menor_distancia;
                X = latitude[i];
                Y = longitude[i];
                ID = id[i];
            }
                
        }
        
        //mostra na tela a parada com menor distancia entre o usuario
        printf("\nPARADA MAIS PROXIMA: %d\n\nPosicao da parada: Latitude: %.3f Longitude: %.3f\n", ID, X, Y);

    }
    else
    {
        printf("Cadastre paradas primeiro!\n");
    }
    
    fclose(file);
}