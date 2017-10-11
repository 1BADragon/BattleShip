#include "bs.h"

int checkBoard(struct game* board)
{
    int i, j, k;
    int p[2] = {1,1};
    for(i=0; i<2; i++)
    {
        for(j=0; j<10; j++)
        {
            for(k=0; k<10; k++)
            {
                if(board->feild[i][j][k] != '*' && board->feild[i][j][k] != 'X' && board->feild[i][j][k] != 'O')
                {
                    p[i] = 0;
                    goto nextloop;
                }
            }
        }
nextloop:
        ;
    }
    if(p[0])
        return 1;
    if(p[1]) 
        return 2;
    return 0;
}