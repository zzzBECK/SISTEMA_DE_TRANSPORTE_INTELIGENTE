#include <stdio.h>
#include "hora.c"

struct trajeto3
{
    int parada, linha, hora, min;
};

void proximosOnibus()
{
    FILE *file;

    struct trajeto3 t;

    int opcao, aux, Horas[100], Mins[100], Linhas[100];
    int HORA, MIN, i = 0;
    int menorH, maiorH, menorM, maiorM, linha, posicao, l = 0;

    HORA = hora();
    MIN = min();

    file = fopen("trajetos.txt", "r");

    if (file != NULL)
    {
        do
        {
            fflush(stdin);
            printf("Escolha o id da parada: ");
            aux = scanf("%d", &opcao);

            if (aux == 0 || opcao <= 0)
                printf("Valor invalido, digite novamente!\n");

            if (!checkIdParada(opcao))
                printf("Parada nao cadastrada!\n");
            
        } while (aux == 0 || opcao <= 0 || !checkIdParada(opcao));

        while(fscanf(file, "%d;%d;%d;%d", &t.parada, &t.linha, &t.hora, &t.min) != EOF)
        {
            if (t.parada == opcao)
            {
                if ((hora() < t.hora) || (hora() == t.hora && min() < t.min))
                {
                    Linhas[i] = t.linha;
                    Horas[i] = t.hora;
                    Mins[i] = t.min;
                    i++;
                }
            }

        }       


        for (int j = 0; j < i; j++)
        {
            menorH = 99;
            maiorH = -99;
            menorM = 99;
            maiorM = -99;

            for (int k = l; k < i; k++)
            {
                if ((Horas[k] < menorH) || (Horas[k] == menorH && Mins[k] < menorM))
                {
                    linha = Linhas[k];
                    menorH = Horas[k];
                    menorM = Mins[k];
                    posicao = k;
                }
            }

            Linhas[posicao] = Linhas[j];
            Linhas[j] = linha;

            Horas[posicao] = Horas[j];
            Horas[j] = menorH;

            Mins[posicao] = Mins[j];
            Mins[j] = menorM;

            l++;
        }

        printf("\nProximos Onibus que passarao na parada %d:\n\n", opcao);

        for (int j = 0; j < i; j++)
        {
            printf("Linha: %d Horario: %.2d:%.2d\n", Linhas[j], Horas[j], Mins[j]);

            if (j == 4)
                break;
        }

    }
    else
    {
        printf("Cadastre trajetos primero!\n");
    } 

    fclose(file);
}
