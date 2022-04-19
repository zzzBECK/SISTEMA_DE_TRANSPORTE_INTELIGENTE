#include <stdio.h>
#include "proximos_onibus.c"
#include "parada_proxima.c"
#define PROXIMOS 1
#define MAIS_PROXIMA 2
#define SAIR_SUT 3

int sutMenu()
{
    int opcao, aux;

    printf ("\n    MENU SUT\n\n"
            "1) Proximos Onibus da Parada\n" // mostra o menu no console
            "2) Qual a parada mais proxima\n"
            "3) Sair\n"
            "\nInsira o valor da opcao: ");


    do
    {
        fflush(stdin);
        aux = scanf("%d", &opcao);

        if (opcao < 1 || opcao > 3 || aux == 0)
            printf("Valor invalido, digite novamente: ");

    } while (opcao < 1 || opcao > 3 || aux == 0);

    system("cls || clear");

    switch (opcao)
    {
        case PROXIMOS:
            proximosOnibus();
            return 1;
        
        case MAIS_PROXIMA:
            paradaProxima();
            return 1;

        case SAIR_SUT:
            return 0;
    }
}