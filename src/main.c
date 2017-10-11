#include "bs.h"

int main()
{
    srand(time(NULL));
    struct game board;
    struct ai computer;
    memset(&board, '*', sizeof(struct game));
    memset(&computer, 0, sizeof(struct ai));
    setUpBoard(&board);
    signal(SIGINT, quitHndl);
    int res;
    memset(msgBuff, 0, sizeof(msgBuff));
    do
    {
        printBoard(&board);
        printf("\e[12;0H");
        playerTurn(&board);
        computerTurn(&board, &computer);
        printf("\n");
		
        res = checkBoard(&board);
    } while(res==0);

    if(res == 1)
        printf("You Lose!!!\n\n");
    else
        printf("You Win!!!\n\n");
    return 0;
}
