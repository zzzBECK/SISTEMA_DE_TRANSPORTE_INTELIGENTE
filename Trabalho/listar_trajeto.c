#include <stdio.h>

// função responsável por printar as linhas e horarios que passam em cada parada
void passaLinha(int id)
{
    FILE *file;
    struct trajeto T;

    // abre o arquivo para leitura
    file = fopen("trajetos.txt", "r");

    //verifica se o arquivo existe
    if (file != NULL)
    {
        printf("\n\nLinhas e horarios que passam na parada:\n");
        
        //loop que armazena os valores contidos no arquivo em variáveis
        while (fscanf(file, "%d;%d;%d;%d", &T.parada, &T.linha, &T.hora, &T.min) != EOF)
        {
            // verifica se a parada é igual a que entrou na função
            if (T.parada == id) 
            {
                // printa junto com as paradas as linhas e horarios que passam
                printf("(Linha: %d  Horario: %.2d:%.2d)\n", T.linha, T.hora, T.min); 
            }   
        }
    }

    // fecha o arquivo
    fclose(file);
}

//função responsável por printar as todas as paradas que cada linha passa
void passaParada(int id)
{
    FILE *file;
    struct trajeto T;
    
    // abre o arquivo para leitrua
    file = fopen("trajetos.txt", "r");

    //verifica se o arquivo existe
    if (file != NULL)
    {
        printf("\n\nParadas que a linha passa:\n");

        // loop que armazena os valores contidos no arquivo em variáveis
        while (fscanf(file, "%d;%d;%d;%d", &T.parada, &T.linha, &T.hora, &T.min) != EOF)
        {
            // verifica se a linha é igual a que entrou na função
            if (T.linha == id)
            {
                // printa junto com as linhas, as paradas que elas passam
                printf("(Parada: %d Horario: %.2d:%.2d)\n", T.parada, T.hora, T.min);
            }   
        }
    }
    
    // fecha o arquivo
    fclose(file);
}