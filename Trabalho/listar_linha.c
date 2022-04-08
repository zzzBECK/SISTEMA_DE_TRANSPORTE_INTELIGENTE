#include <stdio.h>

void listarLinha()
{
    FILE *file;
    struct linha L;

    file = fopen("linhas.txt", "r");

    if (file != NULL)
    {
        printf("LINHAS CADASTRADAS:\n\n");

        while (fscanf(file, "%d", &L.id) != EOF)
        {
            printf("Id: %d", L.id);
            passaParada(L.id);
            printf("\n");
        }
    }
    else
    {
        printf("Nao foi possivel abrir o arquivo, cadastre uma linha antes!\n");
    }
    
    fclose(file);
}