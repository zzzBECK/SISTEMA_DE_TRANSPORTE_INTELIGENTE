#include <stdio.h>
#include "check_trajeto.c"

struct trajeto                              // variaveis para os trajetos
{
    int parada, linha, hora, min;
};

void cadastroTrajeto()
{
    FILE *file;
    struct trajeto T;
    int aux1 = 0, aux2 = 0, aux3 = 0;               // variaveis para contar as tentativas falhas de digitação

    file = fopen("trajetos.txt", "a");

    if(file != NULL)
    {
        do
        {

            do
            {
                if (aux1 == 3)                          // caso haja mais de 3 tentativas erradas de escolher a parada ele sai do loop
                    break;

                printf("Digite o numero da parada: ");
                fflush(stdin);
                scanf("%d", &T.parada);

                if (checkIdParada(T.parada))            // função que verficia se essa parada é cadastrada
                {
                    printf("OK\n");
                }
                else
                {
                    printf("Essa parada nao existe, digite novamente\n");
                    aux1++;
                }
                

            } while (!checkIdParada(T.parada));

            do
            {
                if (aux1 == 3 || aux2 == 3)                 // se houver 3 tentativas erradas de escolher a parada ou a linha, sai do loop
                    break;

                printf("Digite o numero da linha: ");
                fflush(stdin);
                scanf("%d", &T.linha);

                if (checkLinha(T.linha))                    // função que verifica se há essa linha cadastrada
                {
                    printf("OK\n");
                }
                else
                {
                    printf("Essa linha nao existe, digite novamente\n");
                    aux2++;
                }

            } while (!checkLinha(T.linha));

            do
            {
                if (aux1 == 3 || aux2 == 3 || aux3 == 3)     // 3 tentativas de cadastrar paradas, linhas ou horario, sao do loop
                    break;

                printf("Digite o horario (00:00): ");
                fflush(stdin);
                scanf("%d:%d", &T.hora, &T.min);

                if (T.hora < 0 || T.hora > 23 || T.min < 0 || T.min > 59)   // verifica se a hora é valida
                    printf("Esse horario nao existe, digite novamente\n");

                
                if (T.hora < 0 || T.hora > 23 || T.min < 0 || T.min > 59)
                    aux3++;

            } while (T.hora < 0 || T.hora > 23 || T.min < 0 || T.min > 59);

            if (checkTrajeto(T.parada, T.hora, T.min))
                printf("Trajeto ja cadastrado ou horario incompativel com a realidade!\n\nRepita o procedimento!\n\n");

        }while (checkTrajeto(T.parada, T.hora, T.min));


        if (aux1 < 3 && aux2 < 3 && aux3 < 3)   //se nao acabar as tentativas, ele cadastra
        {
            fprintf(file, "%d;%d;%.2d;%.2d\n", T.parada, T.linha, T.hora, T.min);

            printf("\nTrajeto cadastrado com sucesso!\n");
        }
        else if (aux3 == 3)                             // se acabar as tentativas de horario
            printf("\nTentantivas expiradas!\n");
        else                                            // se acabar as tentivas de linhas ou paradas
            printf("\nTentativas expiradas, procure por linhas e paradas cadastradas!\n");


    }

    fclose(file);                                       // fecha o arquivo txt

}