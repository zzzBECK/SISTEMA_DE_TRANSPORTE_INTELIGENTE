#include <stdio.h>
#define TAM_MAX 100

int checkLinha(int id)
{
    FILE *file;
    int tamanho = 0, numeros[TAM_MAX];

    file = fopen("linhas.txt", "r");                                // abre o arquivo para leitura

    if (file != NULL)
    {
        while (fscanf(file, "%d", &numeros[tamanho]) != EOF)        // loop para armazenar as linhas em um vetor
        {
            tamanho++;
        }
    }

    fclose(file);

    for (int i = 0; i < tamanho; i++)
    {
        if (id == numeros[i])                                       // verifica se a linha digitada é igual à alguma linha contida no vetor
            return 1;
    }

    return 0;

}