#include <stdio.h>

//exclui os trajetos vinculados à alguma parada que foi excluida
void excluirTrajetoP(int opcao)
{
    FILE *file, *tempFile;
    struct trajeto t;

    file = fopen("trajetos.txt", "r");
    tempFile = fopen("trajetos.temp", "a");

    //verfica se os arquivos existem
    if (file != NULL && tempFile != NULL)
    {
        //loop para armazenar os valores contidos no arquivo
        while (fscanf(file, "%d;%d;%d;%d", &t.parada, &t.linha, &t.hora, &t.min) != EOF)
        {
            //verificação para copiar todo o conteúdo do primeiro arquivo, com excessão daqueles vinculado a uma parada excluida
            if (t.parada != opcao)
                fprintf(tempFile, "%d;%d;%.2d;%.2d\n", t.parada, t.linha, t.hora, t.min);
        }
    }

    //apaga o arquivo antigo e renomeia o novo arquivo com o mesmo nome do antigo
    fclose(file);
    remove("trajetos.txt");
    fclose(tempFile);
    rename("trajetos.temp", "trajetos.txt");
}

//exclui os trajetos vinculados à alguma linha que foi excluida
void excluirTrajetoL(int opcao)
{
    FILE *file, *tempFile;
    struct trajeto t;

    file = fopen("trajetos.txt", "r");
    tempFile = fopen("trajetos.temp", "a");

    //verifica se os arquivos existem
    if (file != NULL && tempFile != NULL)
    {
        //verificação para copiar todo o conteúdo do primeiro arquivo, com excessão daqueles vinculado a uma linha excluida
        while (fscanf(file, "%d;%d;%d;%d", &t.parada, &t.linha, &t.hora, &t.min) != EOF)
        {
            if (t.linha != opcao)
                fprintf(tempFile, "%d;%d;%.2d;%.2d\n", t.parada, t.linha, t.hora, t.min);
        }
    }
    
    //apaga o arquivo antigo e renomeia o novo arquivo com o mesmo nome do antigo
    fclose(file);
    remove("trajetos.txt");
    fclose(tempFile);
    rename("trajetos.temp", "trajetos.txt");
}