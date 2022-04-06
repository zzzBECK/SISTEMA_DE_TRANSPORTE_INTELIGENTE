#include <stdio.h>

void cadastroParada()
{
    FILE *file;
    float X, Y;
    int id;

    file = fopen("paradas.txt", "a");

    if(file != NULL)
    {
        printf("Digite o numero da parada: ");
        fflush(stdin);
        scanf("%d", &id);
        
        printf("Coordenada X: ");
        scanf("%f", &X);

        printf("Coordenada Y: ");
        scanf("%f", &Y);
        
        fprintf(file, "%d;%.2f;%.2f\n", id, X, Y);

        fclose(file);
    }

}