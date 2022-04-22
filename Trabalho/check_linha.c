#include <stdio.h>

int checkLinha(int id)
{
    FILE *file;
    struct linha L;

    file = fopen("linhas.txt", "r");

    //verifica se o arquivo existe
    if (file != NULL)
    {
        //leitura do arquivo e armazenmanto dos valores em variáveis
        while (fscanf(file, "%d", &L.id) != EOF)
        {
            //verificação se a linha digitada já foi cadastrada anteriormente
            if (id == L.id)
            {
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);

    return 0;

}