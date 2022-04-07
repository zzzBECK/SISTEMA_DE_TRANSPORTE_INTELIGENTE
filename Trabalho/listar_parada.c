#include "listar_trajeto.c"

void listarParada()
{
    FILE *file;
    struct parada P;

    file = fopen("paradas.txt", "r");

    if (file != NULL)
    {
        printf("PARADAS CADASTRADAS:\n\n");

        while (fscanf(file, "%d;%f;%f", &P.id, &P.x, &P.y) != EOF)
        {
            printf("Id: %d  Latitude: %.2f  Longitude: %.2f", P.id, P.x, P.y);
            passaLinha(P.id);
            printf("\n");
            
        }

    }
}