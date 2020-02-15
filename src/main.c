/*
 * Copyright 2020 Matthew Brown
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

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
