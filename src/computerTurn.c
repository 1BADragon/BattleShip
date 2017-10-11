
#include "bs.h"

void computerTurn(struct game *board, struct ai *computer)
{
    int x,y;
    int valid = 0;
    char buf[100];
    memset(buf, 0, sizeof(buf));
    while(!valid)
    {
        x = rand() % 10;
        y = rand() % 10;
        if(board->feild[0][x][y] != 'O' && board->feild[0][x][y] != 'X')
        {
            sprintf(buf, "Computer Shoots %c%d...", (char)(y+'A'), x+1);
            strcat(msgBuff, buf);
            if(board->feild[0][x][y] != '*')
            {
                board->feild[0][x][y] = 'X';
                sprintf(buf, "Hit!!\n");
                strcat(msgBuff, buf);
            }
            else
            {
                board->feild[0][x][y] = 'O';
                sprintf(buf, "Miss!!\n");
                strcat(msgBuff, buf);
            }
            valid = 1;
        }
    }
}