#include "bs.h"

int placeShip(struct game *board, int index, int player)
{
    int x,y,d,size = getSizeOfShip(index);
    int xd,yd,tyd,txd,i;
restart:
    x = rand() % 10;
    y = rand() % 10;
    d = rand() % 4;

    xd = 0, yd = 0;
    getDelta(d, &xd, &yd);
    tyd = yd * size;
    txd = xd * size;
    if(x + txd < 0 || x + txd > 9 || y + tyd < 0 || y + tyd > 9)
    {
        goto restart;
    }

    for(i=0; i<size; i++)
    {
        if(board->feild[player][x+(xd*i)][y+(yd*i)] != '*')
            goto restart;
    }

    for(i=0; i<size; i++)
    {
        board->feild[player][x+(xd*i)][y+(yd*i)] = shipSymbol(index);
    }

    return 0;
}