#include "bs.h"

void quitHndl(int dummy)
{
    printf("\e[2J");
    printf("\e[0;0HQuitter\n");
    exit(0);
}
