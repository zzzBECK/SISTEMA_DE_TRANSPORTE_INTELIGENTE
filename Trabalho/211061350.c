/*
    Eu, Alexandre de Santana Beck, declaro que sou o autor deste código-fonte e que não
    copiei de ou repassei a terceiros. Estou ciente de que a cópia de trabalhos nesta
    turma de Algoritmos e Programação de Computadores é considerada como plágio, constituindo-se
    em grave falta ética e estará sujeita a penalizações na avaliação, incluindo reprovação na disciplina.
*/

#include "sgpl_menu.c"


int main()
{
    while (1) // Loop que so fecha se for digitado 8 no menu
    {
        if (sgplMenu() == 0) // abre o menu SGPL
            break;
    }
    

    return 0;
}