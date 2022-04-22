#include <stdio.h>
#include "excluir_trajeto.c"

void excluirParada()
{
    FILE *file, *tempFile;
    struct parada P;
    int opcao, aux, achei = 0;
    
    file = fopen("paradas.txt", "r");
    tempFile = fopen("paradas.temp", "a");

    //verifica se os arquivos existem
    if (file != NULL && tempFile != NULL)
    {
        do
        {
            fflush(stdin);
            printf("escolha o id da parada a ser excluida: ");
            aux = scanf("%d", &opcao);

            if (aux == 0 || opcao <= 0)
                printf("Valor invalido, digite novamente\n");

        } while (aux == 0 || opcao <= 0);
        //loop para pegar o numero da parada a ser excluida pelo usuário

        excluirTrajetoP(opcao);
        //função contida no arquivo "excluir_trajeto.c" que apaga os trajetos vinculados à parada excluida

        //loop para copiar os dados de um arquivo e colar no outro, com excessão da parada escolhida
        while (fscanf(file, "%d;%f;%f", &P.id, &P.x, &P.y) != EOF)
        {
            if(P.id != opcao)
                fprintf(tempFile, "%d;%.3f;%.3f\n", P.id, P.x, P.y);
            else
                achei = 1;
        }

        //se caso a parada escolhida for cadastrada mostra isso
        if (achei == 1)
        {
            //apaga o arquivo antigo e renomeia o novo arquivo com o mesmo nome do antigo
            printf("\nParada removida com sucesso!\n");
            fclose(file);
            remove("paradas.txt");
            fclose(tempFile);
            rename("paradas.temp", "paradas.txt");
        }
        //se não, mostra isso
        else
        {
            printf("\nParada nao cadastrada!\n");
            fclose(file);
            fclose(tempFile);
            remove("paradas.temp");
        }
        
    }
    //se o arquivo de paradas não existir, mostra isso
    else
    {
        printf("\nCadastre paradas primeiro!\n");
        fclose(file);
        fclose(tempFile);
        remove("paradas.temp");
    }

}