#include "bs.h"

void playerTurn(struct game *board)
{
	char buf[100];
	memset(buf, 0, sizeof(buf));
    unsigned int d,e;
    char c;
beginning:
	printf("\e[12;0H");
    printf("Your Move:\n"
            "+-----+\n"
            "|     |\n"
            "+-----+\n");
    printf("\e[14;2H");
    scanf(" %c%d", &c, &d);
    c = toupper(c);
    e = c - 'A';
    d = d - 1;
    if(e >= 10 || d >= 10)
    {
        sprintf(buf, "Invalid move\n");
		strcat(msgBuff, buf);
        printBoard(board);
        goto beginning;
    }
    if(board->feild[1][d][e] == '*')
    {
        sprintf(buf, "Miss!!\n");
		strcat(msgBuff, buf);
        board->feild[1][d][e] = 'O';
    }
    else if(board->feild[1][d][e] != 'X' && board->feild[1][d][e] != 'O')
    {
        sprintf(buf, "Hit!!\n");
		strcat(msgBuff, buf);
        board->feild[1][d][e] = 'X';
    }
    else
    {
        sprintf(buf, "Already Shot There\n");
		strcat(msgBuff, buf);
        goto beginning;
    }
}