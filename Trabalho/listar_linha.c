#include <stdio.h>

void listarLinha()
{
    FILE *file;
    struct linha L;

    //abre o arquivo para leitura
    file = fopen("linhas.txt", "r");

    //verifica se o arquivo existe
    if (file != NULL)
    {
        printf("LINHAS CADASTRADAS:\n\n");
        printf("-------------------------------------------------------\n\n");

        //armazena os valores contido no arquivo em uma variável
        while (fscanf(file, "%d", &L.id) != EOF)
        {
            //printa na tela o valor da variável através de um loop
            printf("Id: %d", L.id);
            
            //função que printa em quais paradas a linha passa, junto com o horário(pedido do professor em aula)*
            passaParada(L.id);
            printf("\n");
            printf("-------------------------------------------------------\n\n");
        }
    }
    else
    {
        printf("\nCadastre uma linha antes!\n");
    }
    
    fclose(file);
}