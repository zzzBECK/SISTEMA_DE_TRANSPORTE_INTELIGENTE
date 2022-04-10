#include <stdio.h>
#include <stdlib.h>
#include "cadastro_parada.c"
#include "cadastro_linha.c"
#include "cadastro_trajeto.c"
#include "listar_parada.c"
#include "listar_linha.c"
#define CADASTRAR_PARADA 1
#define CADASTRAR_LINHA 2
#define CADASTRAR_TRAJETO 3
#define LISTAS_PARADA 4
#define LISTAR_LINHAS 5
#define SAIR 8

int sgplMenu()
{
    int n, aux;

    printf ("\n1) Cadastrar Parada de Onibus\n" // mostra o menu no console
            "2) Cadastrar Linha de Onibus\n"
            "3) Cadastrar Trajeto\n"
            "4) Listar Paradas Cadastradas\n"
            "5) Listar Linhas Cadastradas\n"
            "6) Excluir Parada de Onibus\n"
            "7) Excluir Linha de Onibus\n"
            "8) Encerrar Programa\n"
            "\nInsira o valor da opcao: ");

    do
    {
        fflush(stdin);
        aux = scanf("%d", &n);

        if (aux == 0 || n < 1 || n > 8)
            printf("Valor invalido, digite novamente: ");


    }while (aux == 0 || n < 1 || n > 8); // verifica se o valor esta dentro do intervalo ou se não é um numero

    system("cls || clear");

    switch (n)
    {
        case CADASTRAR_PARADA:

            cadastroParada();   // chama a função do cadastro_parada.c
            return 1;

        case CADASTRAR_LINHA:

            cadastroLinha();    // chama a função do cadastro_linha.c
            return 1;

        case CADASTRAR_TRAJETO:

            cadastroTrajeto();  // chama a função do cadastro_trajeto.c
            return 1;

        case LISTAS_PARADA:

            listarParada(); // chama a função do listar_parada.c
            return 1;

        case LISTAR_LINHAS:

            listarLinha();  // chama a função do listar_parada.c
            return 1;

        case 6:

            printf("Not Available\n");  // ainda nao funcionado
            return 1;

        case 7:

            printf("Not Available\n");  // ainda nao funcionado
            return 1;

        case SAIR:  // encerra a execução do programa

            return 0;
            
    }
}