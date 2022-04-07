#include <stdio.h>

struct trajeto
{
    int parada, linha, hora, min;
};


void cadastroTrajeto()
{
    FILE *file;
    struct trajeto T;    

    file = fopen("trajetos.txt", "a");

    if(file != NULL)
    {
        do
        {
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
            }

        } while (!checkIdParada(T.parada));


        do
        {

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
            }

        } while (!checkLinha(T.linha));

        printf("Digite o horario (00:00): ");

        do
        {
            fflush(stdin);
            scanf("%d:%d", &T.hora, &T.min);
            if (T.hora < 0 || T.hora > 23 || T.min < 0 || T.min > 59)
                printf("Esse horario nao existe, digite novamente: ");

        } while (T.hora < 0 || T.hora > 23 || T.min < 0 || T.min > 59);


        fprintf(file, "%d;%d;%.2d;%.2d\n", T.parada, T.linha, T.hora, T.min);

        printf("Trajeto cadastrado com sucesso!\n");

    }

    fclose(file);

}