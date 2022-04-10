#include <stdio.h>

int checkCordParada(float x, float y)
{
    FILE *file;
    int tamanho = 0, lixo;
    float X, Y;

    file = fopen("paradas.txt", "r");

    if (file != NULL)
    {
        while (fscanf(file, "%d;%f;%f", &lixo, &X, &Y) != EOF)  // armazena as cordenadas em variaveis
        {
            if (x == X && y == Y)                               // verifica se elas são iguais as digitadas
            {
                fclose(file);
                return 1;                                       // retorna 1 caso os valores digitados sejam identicos aos cadastrados
            }
        }
    }

    fclose(file);

    return 0;
}