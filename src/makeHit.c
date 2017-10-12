#include "bs.h"

struct hit *makeHit(int x, int y, int last_dir)
{
	struct hit *hit;
	int dir,i;
	hit = (struct hit*)calloc(1, sizeof(struct hit));
	hit->x = x;
	hit->y = y;
	hit->last_dir = last_dir;
	
	dir = rand() % 4;
	for(i = 0; i < 4; i++)
	{
		hit->dirs[i] = (dir + i) % 4;
	}
	return hit;
}