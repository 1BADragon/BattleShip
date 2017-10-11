#include "bs.h"

void setUpBoard(struct game *board)
{
    int i;
    for(i = 0; i < 5; i++)
    {
        placeShip(board, i, 0); //place p1's ship
        placeShip(board, i, 1); //place p2's ship
    }
}