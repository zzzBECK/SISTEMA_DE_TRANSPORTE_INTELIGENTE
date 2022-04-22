#include <stdio.h>
#include "check_linha.c"

void cadastroLinha()
{
    FILE *file;
    struct linha L;

    file = fopen("linhas.txt", "a");

    //Verficia se o arquivo existe, como foi aberto para escrita, se ainda não existir ele será criado
    if(file != NULL)
    {
        do
        {
            printf("Digite o numero da linha: ");
            fflush(stdin);
            scanf("%d", &L.id);

            if (checkLinha(L.id))
                printf("Linha ja cadastrada, digite novamente\n");

            if (L.id <= 0)
                printf("Linha inexistente, digite novamente!\n");

        } while (checkLinha(L.id) || L.id <= 0);
        //loop para pegar a linha que o usario deseja cadastrar

        //armazena no arquivo "linhas.txt" o valor escolhido pelo o usuário
        fprintf(file, "%d\n", L.id);

        printf("\nLinha cadastrada com sucesso!\n");

        fclose(file);
    }

}