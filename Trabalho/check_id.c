#include <stdio.h>

int checkIdParada(int id)
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
            //verifica se o numero da parada já é cadastrado
            if (p.id == id)
            {
                fclose(file);
                return 1;
            }

        }
    }

    fclose(file);

    return 0;
}