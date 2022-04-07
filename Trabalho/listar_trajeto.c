#include <stdio.h>

struct trajeto2
{
    int parada, linha, hora, min;
};

void passaLinha(int id)
{
    FILE *file;
    struct trajeto2 T;

    file = fopen("trajetos.txt", "r");

    if (file != NULL)
    {
        while (fscanf(file, "%d;%d;%d;%d", &T.parada, &T.linha, &T.hora, &T.min) != EOF)
        {
            if (T.parada== id)
            {
                printf(" (Linha: %d  Horario: %.2d:%.2d) ", T.linha, T.hora, T.min);
            }   
        }
    }

}

void passaParada(int id)
{
    FILE *file;
    struct trajeto2 T;
    
    file = fopen("trajetos.txt", "r");

    if (file != NULL)
    {
        while (fscanf(file, "%d;%d;%d;%d", &T.parada, &T.linha, &T.hora, &T.min) != EOF)
        {
            if (T.linha== id)
            {
                printf(" (Parada: %d) ", T.parada);
            }   
        }
    }
}