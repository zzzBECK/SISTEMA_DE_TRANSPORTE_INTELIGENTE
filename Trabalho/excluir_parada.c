#include <stdio.h>
#include "excluir_trajeto.c"

struct parada2
{
    int id;
    float x, y;
};


void excluirParada()
{
    FILE *file, *tempFile;
    struct parada2 P;
    int opcao, aux, achei = 0;
    
    file = fopen("paradas.txt", "r");
    tempFile = fopen("paradas.temp", "a");

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

        excluirTrajetoP(opcao);

        while (fscanf(file, "%d;%f;%f", &P.id, &P.x, &P.y) != EOF)
        {
            if(P.id != opcao)
                fprintf(tempFile, "%d;%.3f;%.3f\n", P.id, P.x, P.y);
            else
                achei = 1;
        }

        if (achei == 1)
        {
            printf("\nParada removida com sucesso!\n");
            fclose(file);
            remove("paradas.txt");
            fclose(tempFile);
            rename("paradas.temp", "paradas.txt");
        }
        else
        {
            printf("\nParada nao cadastrada!\n");
            fclose(file);
            fclose(tempFile);
        }
        
    }
    else
    {
        printf("\nCadastre paradas primeiro!\n");
        fclose(file);
        fclose(tempFile);
        remove("paradas.temp");
    }

}