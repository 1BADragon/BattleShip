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
    //scanf(" %c%d", &c, &d);
	do
	{
		c = getchar();
	}
	while(!((c >= 'a' && c <= 'j') ||
			(c >= 'A' && c <= 'J')));
	printf("%c", c);
	do
	{	
		d = getchar() - '0';
	}
	while(!(d >= 0 && d <= 9));
	printf("%d", d);
    c = toupper(c);
	if(d == 0)
		d = 10;
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
