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

#ifndef BS_H
#define BS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#include <stack.h>

char msgBuff[1024];
struct termios old_tp;

struct game {
    char feild[2][10][10];
};

struct ai {
	struct stack *hits;
};

struct hit {
	int x;
	int y;
	int dirs[4];
	int last_dir;
};


int checkBoard(struct game*);
void setUpBoard(struct game*);
int getSizeOfShip(int);
int placeShip(struct game*, int, int);
char shipSymbol(int);
void playerTurn(struct game*);
void computerTurn(struct game*, struct ai*);
void quitHndl(int);
void printBoard(struct game*);
void printSym(char s);
struct hit *makeHit(int, int, int);
void killHit(void *);
void getDelta(int d, int *dx, int *dy);

#endif //BS_H
