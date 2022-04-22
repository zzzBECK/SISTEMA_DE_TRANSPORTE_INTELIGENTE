#include <stdio.h>
#include "hora.c"

int proximosOnibus()
{
    FILE *file;

    struct trajeto t;

    int Horas[100], Mins[100], Linhas[100];

    int menorH, maiorH, menorM, maiorM, linha, posicao, l = 0, i = 0, opcao, aux, tentativas = 0;

    //abre o arquivo para leitura
    file = fopen("trajetos.txt", "r");

    //verifica se o arquivo existe
    if (file != NULL)
    {
        do
        {
            if (tentativas == 3)
            {
                fclose(file);
                printf("\nTentativas expiradas, procura por paradas cadastradas no menu SUT!\n");
                return 0;
            }

            fflush(stdin);
            printf("Escolha o id da parada: ");
            aux = scanf("%d", &opcao);

            if (aux == 0 || opcao <= 0)
                printf("Valor invalido, digite novamente!\n");

            if (!checkIdParada(opcao))
                printf("Parada nao cadastrada!\n");

            tentativas++;
            
        } while (aux == 0 || opcao <= 0 || !checkIdParada(opcao));
        //loop para pegar o numero da parada que o usuario deseja saber os proximos onibus que passarão

        //leitura do arquivo e armazenamento dos valores em suas respectivas variáveis
        while(fscanf(file, "%d;%d;%d;%d", &t.parada, &t.linha, &t.hora, &t.min) != EOF)
        {
            if (t.parada == opcao)
            {
                //funçoes que retornam o horaio atual de acordo com o computador do usuario, e logo em seguida verificam hoarios posterioers ao hoario atual
                if ((hora() < t.hora) || (hora() == t.hora && min() < t.min))
                {
                    Linhas[i] = t.linha;
                    Horas[i] = t.hora;
                    Mins[i] = t.min;
                    i++;
                }
            }

        }       

        // ordenação da listas que possuem os trajetos posteriores ao horario atual, do menor horario ate o maior
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

        // Loop para percorrer por todas as listas e mostrar na tela os proximos onibus que passarão pela parada escolhida pelo o usuário
        for (int j = 0; j < i; j++)
        {
            printf("Linha: %d Horario: %.2d:%.2d\n", Linhas[j], Horas[j], Mins[j]);

            //condição para que mostre apenas os 5 próximos ônibus, caso tenham mais de 5 ao longo do dia
            if (j == 4)
                break;
        }

    }
    else
    {
        printf("Cadastre trajetos primero!\n");
    } 

    //fecha o arquivo
    fclose(file);

    return 0;
}