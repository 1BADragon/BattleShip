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

void computerTurn(struct game *board, struct ai *computer)
{
    int x,y;
	int dx,dy;
    int valid = 0;
    char buf[100];
	struct hit *lasthit;
    memset(buf, 0, sizeof(buf));
	if(getSize(computer->hits) == 0)
	{
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
					push(computer->hits, makeHit(x, y, -1));					
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
	else
	{
		lasthit = (struct hit*)pop(computer->hits);
		x = lasthit->x;
		y = lasthit->y;
		do
		{
			lasthit->last_dir++;
			getDelta(lasthit->last_dir, &dx, &dy);
		}while((((x + dx > 10 || x + dx < 0 || 
			     y + dy > 10 || y + dy < 0) ||
			    (board->feild[0][x+dx][y+dy] == 'X' ||
			     board->feild[0][x+dx][y+dy] == 'O')) &&
				 lasthit->last_dir < 4));
		if(lasthit->last_dir > 3)
		{
			computerTurn(board, computer);
			return;
		}
		else
		{
			if(board->feild[0][x+dx][y+dy] != '*')
			{
				board->feild[0][x+dx][y+dy] = 'X';
				sprintf(buf, "Hit!!\n");
				strcat(msgBuff, buf);
				push(computer->hits, lasthit);
				push(computer->hits, makeHit(x+dx, y+dy, -1));					
			}
			else
			{
				board->feild[0][x+dx][y+dy] = 'O';
				sprintf(buf, "Miss!!\n");
				strcat(msgBuff, buf);
				push(computer->hits, lasthit);
			}
		}			
	}    
}
