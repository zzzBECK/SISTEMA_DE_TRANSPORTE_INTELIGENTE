#include <stdio.h>

void excluirTrajetoP(int opcao)
{
    FILE *file, *tempFile;
    int parada, linha, hora, min;

    file = fopen("trajetos.txt", "r");
    tempFile = fopen("trajetos.temp", "a");

    if (file != NULL && tempFile != NULL)
    {
        while (fscanf(file, "%d;%d;%d;%d", &parada, &linha, &hora, &min) != EOF)
        {
            if (parada != opcao)
                fprintf(tempFile, "%d;%d;%.2d;%.2d\n", parada, linha, hora, min);
        }
    }

    fclose(file);
    remove("trajetos.txt");
    fclose(tempFile);
    rename("trajetos.temp", "trajetos.txt");
}

void excluirTrajetoL(int opcao)
{
    FILE *file, *tempFile;
    int parada, linha, hora, min;

    file = fopen("trajetos.txt", "r");
    tempFile = fopen("trajetos.temp", "a");

    if (file != NULL && tempFile != NULL)
    {
        while (fscanf(file, "%d;%d;%d;%d", &parada, &linha, &hora, &min) != EOF)
        {
            if (linha != opcao)
                fprintf(tempFile, "%d;%d;%.2d;%.2d\n", parada, linha, hora, min);
        }
    }

    fclose(file);
    remove("trajetos.txt");
    fclose(tempFile);
    rename("trajetos.temp", "trajetos.txt");
}