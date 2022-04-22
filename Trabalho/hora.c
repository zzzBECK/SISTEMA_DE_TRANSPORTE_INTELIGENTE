#include <stdio.h>
#include <time.h>

int hora()
{
    time_t my_time;
    struct tm * timeinfo;
    int HORA;

    //pega informações do computador do usuario
    time(&my_time);
    timeinfo = localtime(&my_time);

    //armazena o valor inteiro das horas em uma variavel
    HORA = timeinfo->tm_hour;

    //retorna o valor das horas
    return HORA;
}


int min()
{
    time_t my_time;
    struct tm * timeinfo;
    int MIN;
    
    //pega informações do computador do usuario
    time(&my_time);
    timeinfo = localtime(&my_time);

    //armazena o valor inteiro dos minutos em uma variavel
    MIN = timeinfo->tm_min;

    //retorna o valor dos minutos
    return MIN;
}