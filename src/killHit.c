#include "bs.h"

void killHit(void *hit)
{
	free(hit);
	return;
}