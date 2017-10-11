#include "bs.h"

int getSizeOfShip(int index)
{

    switch(index)
    {
        case 0: //carrier
            return 5;
        case 1: //battleship
            return 4;
        case 2: //Cruiser
        case 3: //Sub
            return 3;
        case 4: //destroyer
            return 2;
    }
    return -1;
}