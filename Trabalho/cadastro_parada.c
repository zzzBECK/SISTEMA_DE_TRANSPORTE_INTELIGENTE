#include <stdio.h>

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
        printf("Digite o numero da parada: ");
        fflush(stdin);
        scanf("%d", &P.id);
        
        printf("Coordenada X: ");
        scanf("%f", &P.x);

        printf("Coordenada Y: ");
        scanf("%f", &P.y);
        
        fprintf(file, "%d;%.2f;%.2f\n", P.id, P.x, P.y);

        fclose(file);
    }

}