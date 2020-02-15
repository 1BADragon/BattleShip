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

int placeShip(struct game *board, int index, int player)
{
    int x,y,d,size = getSizeOfShip(index);
    int xd,yd,tyd,txd,i;
restart:
    x = rand() % 10;
    y = rand() % 10;
    d = rand() % 4;

    xd = 0, yd = 0;
    getDelta(d, &xd, &yd);
    tyd = yd * size;
    txd = xd * size;
    if(x + txd < 0 || x + txd > 9 || y + tyd < 0 || y + tyd > 9)
    {
        goto restart;
    }

    for(i=0; i<size; i++)
    {
        if(board->feild[player][x+(xd*i)][y+(yd*i)] != '*')
            goto restart;
    }

    for(i=0; i<size; i++)
    {
        board->feild[player][x+(xd*i)][y+(yd*i)] = shipSymbol(index);
    }

    return 0;
}
