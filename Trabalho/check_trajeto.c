#include <stdio.h>

int checkTrajeto(int parada, int linha, int hora, int min)
{
    FILE *file;
    struct trajeto T;

    file = fopen("trajetos.txt", "r");

    //verifica se o arquivo existe
    if (file != NULL)
    {
        //leitura do arquivo e armazenamento dos valores em suas respectivas variáveis
        while (fscanf(file, "%d;%d;%d;%d", &T.parada, &T.linha, &T.hora, &T.min) != EOF)
        {
            //vericação se caso o trajeto digitado já tenha sido cadastrado anteriormente
            if (hora == T.hora && min == T.min && T.parada == parada && T.linha == linha)
            {
                fclose(file);
                return 1;
            }
        }
    }
    fclose(file);

    return 0;
}