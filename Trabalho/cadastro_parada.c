#include <stdio.h>
#include "check_id.c"
#include "check_cord.c"
#include <math.h>

void cadastroParada()
{
    FILE *file;
    struct parada P;
    int aux;
    float arredondado;

    file = fopen("paradas.txt", "a");
   
    //Verficia se o arquivo existe, como foi aberto para escrita, se ainda não existir ele será criado
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
                    
            } while (aux == 0);
            //loop para pegar o valor da parada que o usuario digitar

            if (checkIdParada(P.id))
                printf("Parada ja cadastrada, digite novamente\n");
                
            
            if (P.id <= 0)
                printf("Essa parada nao existe, digite novamente\n");

        } while (checkIdParada(P.id) || P.id <= 0);
        //loop que verifica se o valor digiado é valido ou se a parada já foi cadastrada
        
        do
        {
            do
            {
                fflush(stdin);
                printf("Latitude: ");
                aux = scanf("%f", &arredondado);

                //ferramente para evitar arredondamento
                P.x = floor(arredondado * 1000.0f) / 1000.0f;

                if (aux == 0)
                    printf("Valor invalido, digite novamente\n");

            } while (aux == 0);
            //loop para pegar a latitude da parada de acordo com o usuário

            do
            {
                fflush(stdin);
                printf("Longitude: ");
                aux = scanf("%f", &arredondado);

                P.y = floor(arredondado * 1000.0f) / 1000.0f;

                if (aux == 0)
                    printf("Valor invalido, digite novamente\n");

            } while (aux == 0);
            //loop para pegar a longitude da parada de acordo com o usuário

            if (checkCordParada(P.x, P.y))
                printf("Posicao cadastrada com outra parada, digite novamente\n");

        } while (checkCordParada(P.x, P.y));
        //loop que verifica se a coordenada ja foi cadastrada
        
        //armazena no arquivo "paradas.txt" os valores escolhidos pelo usuário
        fprintf(file, "%d;%.3f;%.3f\n", P.id, P.x, P.y);

        printf("\nCadastrado com sucesso!\n");

        fclose(file);
    }

}