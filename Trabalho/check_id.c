#define TAM_MAX 100

int checkIdParada(int id)
{
    FILE *file;
    int numero[TAM_MAX], tamanho = 0;
    float lixo;

    file = fopen("paradas.txt", "r");

    if (file != NULL)
    {
        while (fscanf(file, "%d;%f;%f", &numero[tamanho], &lixo, &lixo) != EOF)
        {
            tamanho++;
        }
    }

    fclose(file);

    for (int i = 0; i < tamanho; i++)
    {
        if (numero[i] == id)
        {
            return 1;
        }
    }


    return 0;
}