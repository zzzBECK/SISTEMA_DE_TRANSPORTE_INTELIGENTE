#include "listar_trajeto.c"

void listarParada()
{
    FILE *file;
    struct parada P;

    file = fopen("paradas.txt", "r");           // abre o arquivo para leitura

    if (file != NULL)
    {
        printf("PARADAS CADASTRADAS:\n\n");

        while (fscanf(file, "%d;%f;%f", &P.id, &P.x, &P.y) != EOF)       // armazena os valores em variaveis
        {
            printf("Id: %d  Latitude: %.3f  Longitude: %.3f", P.id, P.x, P.y);  //printa os valore que estao nas variaveis
            passaLinha(P.id);                               // função que printa as linhas e horarios que passam na parada
            printf("\n");
            
        }
    }
    else
    {
        printf("Nao foi possivel abrir o arquivo, cadastre uma parada antes!\n");
    }
}