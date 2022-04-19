/*
    Eu, Alexandre de Santana Beck, declaro que sou o autor deste código-fonte e que não
    copiei de ou repassei a terceiros. Estou ciente de que a cópia de trabalhos nesta
    turma de Algoritmos e Programação de Computadores é considerada como plágio, constituindo-se
    em grave falta ética e estará sujeita a penalizações na avaliação, incluindo reprovação na disciplina.
*/

#include "sgpl_menu.c"
#include "sut_menu.c"
#define SGPL 1
#define SUT 2


int main()
{

    int opcao, aux;

    while (opcao != 3) // Loop que so fecha se for digitado 8 no menu
    {
        printf("\n----------------------------------------\n");
        printf("1) Menu SGPL\n2) Menu SUT\n3) Encerrar Programa\n\nInsira o valor da opcao: ");

        do
        {
            fflush(stdin);
            aux = scanf("%d", &opcao);

            if (aux == 0 || opcao < 1 || opcao > 3)
                printf("Valor invalido, insira novamente: ");

        } while(aux == 0 || opcao < 1 || opcao > 3);


        system("cls || clear");

        if (opcao == SGPL)
        {
            while (1)
            {
                if (!sgplMenu()) // abre o menu SGPL localizado no arquivo sgpl_menu.c
                    break;
            }

        }

        else if (opcao == SUT)
        {
            while (1)
            {
                if (!sutMenu())
                    break;
            }
        }

    }
    
    return 0;
}