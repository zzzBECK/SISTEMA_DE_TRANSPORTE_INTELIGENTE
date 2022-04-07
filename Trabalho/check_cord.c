#include <stdio.h>

int checkCordParada(float x, float y)
{
    FILE *file;
    int tamanho = 0, lixo;
    float X, Y;

    file = fopen("paradas.txt", "r");

    if (file != NULL)
    {
        while (fscanf(file, "%d;%f;%f", &lixo, &X, &Y) != EOF)
        {
            if (x == X && y == Y)
            {
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);

    return 0;
}