#include "bs.h"

void printSym(char c)
{
    switch(c)
    {
        case '*':
            printf("\e[34m");
            break;
        case 'X':
            printf("\e[31m");
            break;
        case 'O':
            printf("\e[33m");
            break;
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 's':
            printf("\e[32m");
            break;
        default:
            printf("\e[39m");
    }
    printf("%c\e[39m", c);
}