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
