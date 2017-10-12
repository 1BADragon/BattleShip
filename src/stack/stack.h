#ifndef STACK_H
#define STACK_H

#include <stdlib.h> //calloc
#include <stdio.h> //fprintf

struct node
{
	void *data;
	struct node *next;
};

struct stack
{
	struct node *head;
	unsigned int size;
};

struct stack *makeStack();
unsigned int getSize(struct stack *);
void killStack(struct stack *, void (*free_data)(void *));

void push(struct stack *, void *);
void *pop(struct stack *);



#endif