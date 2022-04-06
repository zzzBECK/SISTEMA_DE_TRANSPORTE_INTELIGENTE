struct linha
{
    int id;
};


void cadastroLinha()
{
    FILE *file;
    struct linha L;

    file = fopen("linhas.txt", "a");

    if(file != NULL)
    {
        printf("Digite o numero da linha: ");
        fflush(stdin);
        scanf("%d", &L.id);
        
        fprintf(file, "%d\n", L.id);

        fclose(file);
    }

}