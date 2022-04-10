#include <stdio.h>
#include "check_linha.c"

struct linha     // variáveis para as linhas
{
    int id;
};


void cadastroLinha()
{
    FILE *file;
    struct linha L;

    file = fopen("linhas.txt", "a");                                    // abre o arquivo para escrita

    if(file != NULL)
    {
        do
        {
            printf("Digite o numero da linha: ");
            fflush(stdin);
            scanf("%d", &L.id);

            if (checkLinha(L.id))
                printf("Linha ja cadastrada, digite novamente\n");

        } while (checkLinha(L.id));                                     // fumcao que verifica se já tem a linha cadastrada

        
        fprintf(file, "%d\n", L.id);

        printf("Linha cadastrada com sucesso!\n");

        fclose(file);                                                   // fecha o arquivo
    }

}