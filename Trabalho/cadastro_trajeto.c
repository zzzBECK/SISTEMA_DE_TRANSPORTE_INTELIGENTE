#include "check.c"

void cadastroTrajeto()
{
    FILE *file;
    int parada, linha, hora, min;

    file = fopen("trajetos.txt", "a");

    if(file != NULL)
    {
        do
        {
            printf("Digite o numero da parada: ");
            fflush(stdin);
            scanf("%d", &parada);

            if (checkParada(parada))
            {
                printf("OK\n");
            }
            else
            {
                printf("Essa parada nao existe, digite novamente\n");
            }

        } while (!checkParada(parada));


        do
        {

            printf("Digite o numero da linha: ");
            fflush(stdin);
            scanf("%d", &linha);

            if (checkLinha(linha))
            {
                printf("OK\n");
            }
            else
            {
                printf("Essa linha nao existe, digite novamente\n");
            }

        } while (!checkLinha(linha));

        printf("Digite o horario (00:00): ");

        do
        {
            fflush(stdin);
            scanf("%d:%d", &hora, &min);
            if (hora < 0 || hora > 24 || min < 0 || min > 59)
                printf("Esse horario nao existe, digite novamente: ");

        } while (hora < 0 || hora > 24 || min < 0 || min > 59);


        fprintf(file, "%d;%d;%.2d;%.2d\n", parada, linha, hora, min);

    }

    fclose(file);

}