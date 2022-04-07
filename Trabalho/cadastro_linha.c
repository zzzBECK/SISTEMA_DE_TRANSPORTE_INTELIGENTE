#include <stdio.h>
#include "check_linha.c"

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
        do
        {
            printf("Digite o numero da linha: ");
            fflush(stdin);
            scanf("%d", &L.id);

            if (checkLinha(L.id))
                printf("Linha ja cadastrada, digite novamente\n");

        } while (checkLinha(L.id));

        
        fprintf(file, "%d\n", L.id);

        printf("Linha cadastrada com sucesso!\n");

        fclose(file);
    }

}