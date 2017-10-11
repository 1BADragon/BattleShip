#include "bs.h"

char shipSymbol(int index)
{
    switch(index)
    {
        case 0:
            return 'a';
        case 1:
            return 'b';
        case 2: 
            return 'c';
        case 3:
            return 's';
        case 4: 
            return 'd';
    }
    return '\0';
}