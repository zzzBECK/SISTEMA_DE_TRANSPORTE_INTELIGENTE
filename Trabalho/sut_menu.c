#include <stdio.h>
#include "proximos_onibus.c"
#include "parada_proxima.c"
#define PROXIMOS 1
#define MAIS_PROXIMA 2
#define SAIR_SUT 3

int sutMenu()
{
    int opcao, aux;

    // mostra o menu no console
    printf ("\n    MENU SUT\n\n"
            "1) Proximos Onibus da Parada\n" 
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
    //loop para pegar a opcao do usuario

    //limpa o console
    system("cls || clear");

    switch (opcao)
    {
        //chama a função contida no arquivo "proximos_onibus.c"
        case PROXIMOS:
            proximosOnibus();
            return 1;
        
        //chama a função contida no arquivo "parada_proxima.c"
        case MAIS_PROXIMA:
            paradaProxima();
            return 1;

        // Retorna para o menu principal
        case SAIR_SUT:
            return 0;
    }
}