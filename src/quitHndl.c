#include "bs.h"

void quitHndl(int dummy)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &old_tp);
    printf("\e[2J");
    printf("\e[0;0HQuitter\n");
    exit(0);
}
