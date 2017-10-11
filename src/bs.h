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

char msgBuff[1024];

struct game {
    char feild[2][10][10];
};

struct ai {

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

#endif //BS_H