
#include <stack.h>

struct stack *makeStack()
{
	return (struct stack *)calloc(1, sizeof(struct stack));
}