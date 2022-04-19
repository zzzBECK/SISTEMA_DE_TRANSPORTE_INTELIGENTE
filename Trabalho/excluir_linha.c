#include <stdio.h>

void excluirLinha()
{
    FILE *file, *tempFile;
    int linha, opcao, aux, achei = 0;


    file = fopen("linhas.txt", "r");
    tempFile = fopen("linhas.temp", "a");

    if (file != NULL && tempFile != NULL)
    {
        do
        {
            fflush(stdin);
            printf("escolha o id da linha a ser excluida: ");
            aux = scanf("%d", &opcao);

            if (aux == 0 || opcao <= 0)
                printf("valor invalido, digite novamente\n");

        } while (opcao <= 0 || aux == 0);

        excluirTrajetoL(opcao);

        while (fscanf(file, "%d", &linha) != EOF)
        {
            if (linha != opcao)
                fprintf(tempFile, "%d\n", linha);
            else
                achei = 1;
        }

        if (achei == 1)
        {
            printf("\nLinha removida com sucesso!\n");
            fclose(file);
            remove("linhas.txt");
            fclose(tempFile);
            rename("linhas.temp", "linhas.txt");
        }
        else
        {
            printf("\nLinha nao cadastrada!\n");
            fclose(file);
            fclose(tempFile);
        }


    }
    else
    {
        printf("\nCadastre linhas primeiro!\n");
        fclose(file);
        fclose(tempFile);
        remove("linhas.temp");
    }
}