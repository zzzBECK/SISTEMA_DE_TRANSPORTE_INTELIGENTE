#include "sgpl_menu.c"

int main()
{
    while (1)
    {
        if (sgplMenu() == 0)
            break;
    }
    

    return 0;
}