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


int checkParada(int id)
{
    FILE *file;
    int tamanho = 0, numeros[TAM_MAX];
    float lixo;

    file = fopen("paradas.txt", "r");

    if (file != NULL)
    {
        while (fscanf(file, "%d;%f;%f", &numeros[tamanho], &lixo, &lixo) != EOF)
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