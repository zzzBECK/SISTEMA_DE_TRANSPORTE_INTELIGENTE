#include <stdio.h>

struct trajeto2                          // variaveis para o trajeto
{
    int parada, linha, hora, min;
};

void passaLinha(int id)
{
    FILE *file;
    struct trajeto2 T;

    file = fopen("trajetos.txt", "r");          // abre o arquivo para leitura

    if (file != NULL)
    {
        while (fscanf(file, "%d;%d;%d;%d", &T.parada, &T.linha, &T.hora, &T.min) != EOF)  // armazena os valores em variaveis
        {
            if (T.parada == id)        // se a parada é igual a de algum trajeto  
            {
                printf(" (Linha: %d  Horario: %.2d:%.2d) ", T.linha, T.hora, T.min); // printa junto com as paradas as linhas e horarios que passam
            }   
        }
    }

    fclose(file);           // fecha o arquivo
}

void passaParada(int id)
{
    FILE *file;
    struct trajeto2 T;
    
    file = fopen("trajetos.txt", "r");  // abre o arquivo para leitrua

    if (file != NULL)
    {
        while (fscanf(file, "%d;%d;%d;%d", &T.parada, &T.linha, &T.hora, &T.min) != EOF)  // armazena os valores em variaveis
        {
            if (T.linha== id)          // verifica se a linha é igual a que entrou na funcao
            {
                printf(" (Parada: %d) ", T.parada);   // printa junto as linhas, as paradas que elas passam
            }   
        }
    }
    
    fclose(file);           // fecha o arquivo
}