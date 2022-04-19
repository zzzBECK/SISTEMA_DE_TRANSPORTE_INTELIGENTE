#include <stdio.h>

void listarLinha()
{
    FILE *file;
    struct linha L;

    file = fopen("linhas.txt", "r");        // abre o arquivo para leitrua

    if (file != NULL)
    {
        printf("LINHAS CADASTRADAS:\n\n");

        while (fscanf(file, "%d", &L.id) != EOF)   // armazena os valores na variavel
        {
            printf("Id: %d", L.id);                // printa a variavel
            passaParada(L.id);                     // função que printa as paradas que a linha passa
            printf("\n");
        }
    }
    else
    {
        printf("\nCadastre uma linha antes!\n");
    }
    
    fclose(file);
}