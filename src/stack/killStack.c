#include "stack.h"

void killStack(struct stack *stack, void (*free_data)(void *))
{
	struct node *curr;
	struct node *next;
	
	next = stack->head;
	
	while(next != NULL)
	{
		curr = next;
		next = curr->next;
		free_data(curr->data);
		free(curr);
	}
}