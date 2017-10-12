#include <stack.h>

void push(struct stack *stack, void *data)
{
	struct node *node = calloc(1, sizeof(struct node));
	if(node == NULL)
	{
		fprintf(stderr, "Memory Error!!");
		exit(1);
	}
	node->data = data;
	node->next = stack->head;
	
	stack->head = node;
	stack->size++;
}