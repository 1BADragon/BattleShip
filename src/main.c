#include "bs.h"

int main()
{
	char c;
    srand(time(NULL));
    struct game board;
    struct ai computer;
	memset(&board, '*', sizeof(struct game));
    memset(&computer, 0, sizeof(struct ai));
	struct termios tp;
	if(tcgetattr(STDIN_FILENO, &tp) == -1)
	{
		printf("tcgetattr\n");
		exit(1);
	}
	old_tp = tp;
	tp.c_lflag &= ~ECHO;
	tp.c_lflag &= ~ICANON;
	if(tcsetattr(STDIN_FILENO, TCSANOW, &tp) == -1)
	{
		printf("tcsetattr\n");
		exit(1);
	}
	
	computer.hits = makeStack();
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
	
	printBoard(&board);
    if(res == 1)
        printf("You Lose!!!\n\n");
    else
        printf("You Win!!!\n\n");
	
	printf("Hit enter to exit\n");
	printf("\e[0;0H");
	
	scanf("%c", &c);
	printf("\033[2J");
	
	tcsetattr(STDIN_FILENO, TCSANOW, &old_tp);
	
    return 0;
}
