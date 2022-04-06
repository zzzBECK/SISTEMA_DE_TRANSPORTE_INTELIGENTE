#include <stdio.h>
#include "cadastro_parada.c"
#include "cadastro_linha.c"
#include "cadastro_trajeto.c"

int Menu()
{
    int n;

    printf ("1) Cadastrar Parada de Onibus\n"
            "2) Cadastrar Linha de Onibus\n"
            "3) Cadastrar Trajeto\n"
            "4) Listar Paradas Cadastradas\n"
            "5) Listar Linhas Cadastradas\n"
            "6) Excluir Parada de Onibus\n"
            "7) Excluir Linha de Onibus\n"
            "8) Encerrar Programa\n");

    do
        scanf("%d", &n);
    while (n < 1 || n > 8);

    switch (n)
    {
        case 1:
            cadastroParada();
            return 1;
        case 2:
            cadastroLinha();
            return 1;
        case 3:
            cadastroTrajeto();
            return 1;
        case 4:
            printf("Not Available\n");
            return 1;
        case 5:
            printf("Not Available\n");
            return 1;
        case 6:
            printf("Not Available\n");
            return 1;
        case 7:
            printf("Not Available\n");
            return 1;
        case 8:
            return 0;
            
    }
}