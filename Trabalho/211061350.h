#define TAM_MAX 100

struct linha
{
    int id;
};

struct parada
{
    int id;
    float x, y;
};

struct trajeto
{
    int parada, linha, hora, min;
};