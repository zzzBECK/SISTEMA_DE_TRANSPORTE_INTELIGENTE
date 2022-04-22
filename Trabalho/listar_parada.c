#include "listar_trajeto.c"

void listarParada()
{
    FILE *file;
    struct parada P;
    
    //abre o arquivo para leitura
    file = fopen("paradas.txt", "r");

    //verifica se o arquivo existe
    if (file != NULL)
    {
        printf("PARADAS CADASTRADAS:\n\n");
        printf("-------------------------------------------------------\n\n");

        // armazena os valores em variaveis
        while (fscanf(file, "%d;%f;%f", &P.id, &P.x, &P.y) != EOF)
        {
            //printa os valores das contidos nas variáveis na tela
            printf("Id: %d  Latitude: %.3f  Longitude: %.3f", P.id, P.x, P.y);

            // função que printa as linhas e horarios que passam na parada, esta no arquivo listar_trajeto.c
            passaLinha(P.id);
            printf("\n");
            printf("-------------------------------------------------------\n\n");
            
        }
    }
    else
    {
        printf("\nCadastre uma parada antes!\n");
    }

    fclose(file);
}