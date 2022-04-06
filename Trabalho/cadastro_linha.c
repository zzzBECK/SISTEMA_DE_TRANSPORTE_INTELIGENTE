void cadastroLinha()
{
    FILE *file;
    int id;

    file = fopen("linhas.txt", "a");

    if(file != NULL)
    {
        printf("Digite o numero da linha: ");
        fflush(stdin);
        scanf("%d", &id);
        
        fprintf(file, "%d\n", id);

        fclose(file);
    }

}