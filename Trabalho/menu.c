#include <stdio.h>

int Menu()
{
    int n;

    printf("1) Cadastrar Parada de Onibus\n"
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
        case 8:
            return 0;
            break;
            
    }
}