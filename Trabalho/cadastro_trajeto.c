#include <stdio.h>
#include "check_trajeto.c"

int cadastroTrajeto()
{
    FILE *file;
    struct trajeto T;
    int tentativas = 0;

    file = fopen("trajetos.txt", "a");

    //Verficia se o arquivo existe, como foi aberto para escrita, se ainda não existir ele será criado
    if(file != NULL)
    {
        do
        {

            do
            {
                // caso haja mais de 3 tentativas erradas de escolher a parada ele sai do loop
                if (tentativas == 3)
                {
                    fclose(file);
                    printf("\nTentativas expiradas, procure por paradas cadastradas!\n");
                    return 0;
                }                         

                printf("Digite o numero da parada: ");
                fflush(stdin);
                scanf("%d", &T.parada);

                if (checkIdParada(T.parada))
                {
                    printf("OK\n");
                }
                else
                {
                    printf("Essa parada nao existe, digite novamente\n");
                    tentativas++;
                }
                

            } while (!checkIdParada(T.parada));
            //loop para pegar o numero da parada de acordo com o usuário e verificar se ele existe

            tentativas = 0;

            do
            {
                // se houver 3 tentativas erradas de escolher a linha
                if (tentativas == 3)
                {
                    fclose(file);
                    printf("\nTentativas expiradas, procure por linhas cadastradas!\n");
                    return 0;
                }
                    

                printf("Digite o numero da linha: ");
                fflush(stdin);
                scanf("%d", &T.linha);

                if (checkLinha(T.linha))
                {
                    printf("OK\n");
                }
                else
                {
                    printf("Essa linha nao existe, digite novamente\n");
                    tentativas++;
                }

            } while (!checkLinha(T.linha));
            //loop para pegar o numero da linha de acordo com o usuário e verificar se ele existe

            tentativas = 0;

            do
            {
                // 3 tentativas de cadastrar paradas, linhas ou horario, sai do loop
                if (tentativas == 3)
                {
                    fclose(file);
                    printf("\nTentativas expiradas!\n");
                    return 0;
                }

                printf("Digite o horario (00:00): ");
                fflush(stdin);
                scanf("%d:%d", &T.hora, &T.min);

                if (T.hora < 0 || T.hora > 23 || T.min < 0 || T.min > 59)
                {
                    printf("Esse horario nao existe, digite novamente\n");
                    tentativas++;
                }

            } while (T.hora < 0 || T.hora > 23 || T.min < 0 || T.min > 59);
            //loop para pegar o horário de acordo com usuário e verificar se é um horário válido

            if (checkTrajeto(T.parada, T.linha, T.hora, T.min))
                printf("Trajeto ja cadastrado\n\nRepita o procedimento!\n\n");

        }while (checkTrajeto(T.parada, T.linha, T.hora, T.min));
        //loop para verficar se já tem um mesmo trajeto cadastrado

        //armazenamento no arquivo "trajetos.txt" de acordo com os valores escolhidos pelo usuário
        fprintf(file, "%d;%d;%.2d;%.2d\n", T.parada, T.linha, T.hora, T.min);

        printf("\nTrajeto cadastrado com sucesso!\n");

    }

    fclose(file);

    return 0;

}