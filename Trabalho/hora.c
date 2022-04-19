#include <stdio.h>
#include <time.h>

int hora()
{
    time_t my_time;
    struct tm * timeinfo;
    int HORA;

    time(&my_time);
    timeinfo = localtime(&my_time);

    HORA = timeinfo->tm_hour;

    return HORA;
}


int min()
{
    time_t my_time;
    struct tm * timeinfo;
    int MIN;

    time(&my_time);
    timeinfo = localtime(&my_time);

    MIN = timeinfo->tm_min;

    return MIN;
}