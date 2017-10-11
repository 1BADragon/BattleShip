#include "bs.h"

void printBoard(struct game *board)
{
    int i,j,k;
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int lines = w.ws_row;
    printf("\033[2J"); //clear screen
    printf("\033[0;0H"); //move cursor to top left of screen
    for(i = 0; i < 2; i++)
    {
        printf("   ");
        for(j = 0; j < 10; j++)
        {
            printf("%c ", 'A' + j);
        }
        printf("\t");
    }
    printf("\n");

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 2; j++)
        {
            if(i < 9)
            {
                printf(" ");
            }
            printf("%d ", i+1);
            for(k = 0; k < 10; k++)
            {
                if(j==0)
                {
                    printSym(board->feild[j][i][k]);
                    printf(" ");
                }
                else
                {
                    if(board->feild[j][i][k] !='O' && 
                            board->feild[j][i][k] != 'X')
                    {
                        printSym('*');
                        printf(" ");
                    }
                    else
                    {
                        printSym(board->feild[j][i][k]);
                        printf(" ");
                    }
                }
            }
            printf("\t");
        }
        printf("\n");
    }
	if(lines >= 20 && msgBuff[0] != '\0')
	{
		printf("\e[20;0HMessages:\n%s\n", msgBuff);
	}
    memset(msgBuff, 0, sizeof(msgBuff));
}