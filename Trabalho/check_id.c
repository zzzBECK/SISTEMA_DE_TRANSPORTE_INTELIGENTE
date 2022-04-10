#define TAM_MAX 100

int checkIdParada(int id)
{
    FILE *file;
    int numero[TAM_MAX], tamanho = 0;
    float lixo;

    file = fopen("paradas.txt", "r");

    if (file != NULL)
    {
        while (fscanf(file, "%d;%f;%f", &numero[tamanho], &lixo, &lixo) != EOF)   // armazena os numeros das paradas em um vetor
        {
            tamanho++;   // variavel para a posição do vetor
        }
    }

    fclose(file);

    for (int i = 0; i < tamanho; i++)
    {
        if (numero[i] == id)                    // verifica se o novo id digitado seja igual a alguns dos valores do vetor
        {
            return 1;
        }
    }


    return 0;
}