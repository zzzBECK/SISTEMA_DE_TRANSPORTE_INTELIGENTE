#include <stdio.h>

int checkCordParada(float x, float y)
{
    FILE *file;
    struct parada p;

    file = fopen("paradas.txt", "r");

    //verifica se o arquivo existe
    if (file != NULL)
    {
        //leitura do arquivo e armazenamento dos valores em variáveis
        while (fscanf(file, "%d;%f;%f", &p.id, &p.x, &p.y) != EOF)
        {
            //verificação se caso as coordenadas sejam iguais às cadastradas
            if (x == p.x && y == p.y)
            {
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);

    return 0;
}