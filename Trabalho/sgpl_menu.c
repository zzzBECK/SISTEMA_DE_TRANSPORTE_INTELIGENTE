#include <stdio.h>
#include <stdlib.h>
#include "cadastro_parada.c"
#include "cadastro_linha.c"
#include "cadastro_trajeto.c"
#include "listar_parada.c"
#include "listar_linha.c"
#include "excluir_parada.c"
#include "excluir_linha.c"
#define CADASTRAR_PARADA 1
#define CADASTRAR_LINHA 2
#define CADASTRAR_TRAJETO 3
#define LISTAS_PARADA 4
#define LISTAR_LINHAS 5
#define EXCLUIR_PARADA 6
#define EXCLUIR_LINHA 7
#define SAIR 8

int sgplMenu()
{
    int n, aux;

    // mostra as opções do menu para o usuário
    printf ("\n    MENU SGPL\n"
            "\n1) Cadastrar Parada de Onibus\n"
            "2) Cadastrar Linha de Onibus\n"
            "3) Cadastrar Trajeto\n"
            "4) Listar Paradas Cadastradas\n"
            "5) Listar Linhas Cadastradas\n"
            "6) Excluir Parada de Onibus\n"
            "7) Excluir Linha de Onibus\n"
            "8) Sair\n"
            "\nInsira o valor da opcao: ");

    do
    {
        fflush(stdin);
        aux = scanf("%d", &n);

        if (aux == 0 || n < 1 || n > 8)
            printf("Valor invalido, digite novamente: ");


    }while (aux == 0 || n < 1 || n > 8);
    //loop para pegar a opção do usuário

    //limpa as informações do console (apaga tudo)
    system("cls || clear");

    switch (n)
    {
        case CADASTRAR_PARADA:

            // chama a função do "cadastro_parada.c"
            cadastroParada();
            return 1;

        case CADASTRAR_LINHA:

            // chama a função do "cadastro_linha.c"
            cadastroLinha();
            return 1;

        case CADASTRAR_TRAJETO:

            // chama a função do "cadastro_trajeto.c"
            cadastroTrajeto();
            return 1;

        case LISTAS_PARADA:

            // chama a função do "listar_parada.c"
            listarParada();
            return 1;

        case LISTAR_LINHAS:

            // chama a função do "listar_parada.c"
            listarLinha();
            return 1;

        case EXCLUIR_PARADA:

            //chama a função do "excluir_parada.c"
            excluirParada();
            return 1;

        case EXCLUIR_LINHA:

            //chama a função do "excluir_linha.c"
           excluirLinha();
            return 1;

        case SAIR:
            //retorna para o menu principal
            return 0;
            
    }
}