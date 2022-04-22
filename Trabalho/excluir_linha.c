#include <stdio.h>

void excluirLinha()
{
    FILE *file, *tempFile;
    int linha, opcao, aux, achei = 0;

    file = fopen("linhas.txt", "r");
    tempFile = fopen("linhas.temp", "a");

    //verifica se o arquivo de linhas existe
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
        //loop para pegar a linha em que o usuário deseja excluir

        //exclui os valores vinculados à linha escolhida no arquivo "trajetos.txt"
        excluirTrajetoL(opcao);

        //loop que lê o arquivo das linhas e escreve em outro aruqivo todos os valores exceto à linha escolhida para ser excluida
        while (fscanf(file, "%d", &linha) != EOF)
        {
            if (linha != opcao)
                fprintf(tempFile, "%d\n", linha);
            else
                achei = 1;
        }

        //mostra se a linha foi excluida com sucesso
        if (achei == 1)
        {
            printf("\nLinha removida com sucesso!\n");
            fclose(file);
            remove("linhas.txt");
            fclose(tempFile);
            rename("linhas.temp", "linhas.txt");
        }

        //mostra se a linha digitada não é cadastrada no sistema
        else
        {
            printf("\nLinha nao cadastrada!\n");
            fclose(file);
            fclose(tempFile);
            remove("linhas.temp");
        }


    }

    //mostra na tela quando o arquivo de linhas não existe ainda
    else
    {
        printf("\nCadastre linhas primeiro!\n");
        fclose(file);
        fclose(tempFile);
        remove("linhas.temp");
    }
}