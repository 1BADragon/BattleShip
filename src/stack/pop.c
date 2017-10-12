#include <stack.h>

void *pop(struct stack *stack)
{
	if(stack->head == NULL)
	{
		return NULL;
	}
	struct node *head = stack->head;
	void *ret = head->data;
	stack->head = head->next;
	free(head);
	stack->size--;
	return ret;
}