#include <stdio.h>
#define TAM_MAX 100

int checkLinha(int id)
{
    FILE *file;
    int tamanho = 0, numeros[TAM_MAX];

    file = fopen("linhas.txt", "r");

    if (file != NULL)
    {
        while (fscanf(file, "%d", &numeros[tamanho]) != EOF)
        {
            tamanho++;
        }
    }

    fclose(file);

    for (int i = 0; i < tamanho; i++)
    {
        if (id == numeros[i])
            return 1;
    }

    return 0;

}