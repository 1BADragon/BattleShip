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