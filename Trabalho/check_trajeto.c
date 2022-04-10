#include <stdio.h>

int checkTrajeto(int parada, int hora, int min)
{
    FILE *file;
    int Tmin, Thora, Tparada, lixo;

    file = fopen("trajetos.txt", "r");

    if (file != NULL)
    {
        while (fscanf(file, "%d;%d;%d;%d", &Tparada, &lixo, &Thora, &Tmin) != EOF)   // armazena os valores em variaveis
        {
            if (hora == Thora && min == Tmin && Tparada == parada)                   // verifica se ja tem um trajeto igual de acordo com essas variaveis
                return 1;
        }
    }
    fclose(file);

    return 0;
}