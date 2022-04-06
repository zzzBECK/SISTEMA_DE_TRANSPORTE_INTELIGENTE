int checkLinha(int n)
{
    FILE *file;
    int tamanho = 0, numeros[100];

    file = fopen("linhas.txt", "r");

    if (file != NULL)
    {
        while(fscanf(file, "%d", &numeros[tamanho]) != EOF)
        {
            tamanho++;
        }
    }

    fclose(file);

    for (int i = 0; i < tamanho; i++)
    {
        if (n == numeros[i])
            return 1;
    }

    return 0;

}