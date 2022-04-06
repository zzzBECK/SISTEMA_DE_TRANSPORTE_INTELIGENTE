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
            printf("Id: %d\n", L.id);
        }

    }
}