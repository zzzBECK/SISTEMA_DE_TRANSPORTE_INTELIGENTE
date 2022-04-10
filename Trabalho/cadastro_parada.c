#include <stdio.h>
#include "check_id.c"
#include "check_cord.c"

struct parada                // variaveis para as paradas
{
    int id;
    float x, y;
};


void cadastroParada()
{
    FILE *file;
    struct parada P;
    int aux;

    file = fopen("paradas.txt", "a");

    if(file != NULL)
    {
        do
        {
            do
            {
                printf("Digite o numero da parada: ");
                fflush(stdin);
                aux = scanf("%d", &P.id);

                if (aux == 0)
                    printf("Essa parada nao existe, digite novamente\n");
                    
            } while (aux == 0);                                                 // Verfica se o input é um numero


            if (checkIdParada(P.id))                                            // funcao que verifica se a parada já está cadastrada
                printf("Parada ja cadastrada, digite novamente\n");
                
            
            if (P.id <= 0)                                                      // Predefinição de que não exista paradas abaixo de 0
                printf("Essa parada nao existe, digite novamente\n");

        } while(checkIdParada(P.id) || P.id <= 0);                              // Loop para que as condições à cima sejam cumpridas
        
        do
        {
            do
            {
                fflush(stdin);
                printf("Latitude: ");
                aux = scanf("%f", &P.x);

                if (aux == 0)
                    printf("Valor invalido, digite novamente\n");

            } while (aux == 0);                                                 // verifica se é um numero

            do
            {
                fflush(stdin);
                printf("Longitude: ");
                aux = scanf("%f", &P.y);

                if (aux == 0)
                    printf("Valor invalido, digite novamente\n");

            } while (aux == 0);                                                 // verifica se é um numero

            if (checkCordParada(P.x, P.y))                                      // funcao que verifica que se outra parada ja tem essas coordenadas
                printf("Posicao cadastrada com outra parada, digite novamente\n");

        } while (checkCordParada(P.x, P.y));
        
        fprintf(file, "%d;%.3f;%.3f\n", P.id, P.x, P.y);

        printf("Cadastrado com sucesso!\n");

        fclose(file);
    }

}