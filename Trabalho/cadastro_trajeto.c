#include "check.c"

void cadastroTrajeto()
{
    FILE *file;
    int parada, linha, horario;

    file = fopen("trajetos.txt", "a");

    if(file != NULL)
    {
        printf("Digite o numero da parada: ");
        fflush(stdin);
        scanf("%d", &parada);
        checkLinha(parada);

        fclose(file);
    }

}