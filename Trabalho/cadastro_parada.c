#include <stdio.h>
#include "check_id.c"
#include "check_cord.c"

struct parada
{
    int id;
    float x, y;
};


void cadastroParada()
{
    FILE *file;
    struct parada P;

    file = fopen("paradas.txt", "a");

    if(file != NULL)
    {
        do
        {
            printf("Digite o numero da parada: ");
            fflush(stdin);
            scanf("%d", &P.id);

            if (checkIdParada(P.id))
                printf("Parada ja cadastrada, digite novamente\n");
        } while(checkIdParada(P.id));
        
        do
        {
            printf("Latitude: ");
            scanf("%f", &P.x);

            printf("Longitude: ");
            scanf("%f", &P.y);

            if (checkCordParada(P.x, P.y))
                printf("Posicao cadastrada com outra parada, digite novamente\n");

        } while (checkCordParada(P.x, P.y));
        
        fprintf(file, "%d;%.2f;%.2f\n", P.id, P.x, P.y);

        printf("Cadastrado com sucesso!\n");

        fclose(file);
    }

}