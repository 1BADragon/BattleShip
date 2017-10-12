void getDelta(int d, int *dx, int *dy)
{
	switch(d)
	{
	case 0:
		*dy = 1;
		*dx = 0;
		break;
	case 1:
		*dy = 0;
		*dx = 1;
		break;
	case 2:
		*dy = -1;
		*dx = 0;
		break;
	case 3:
		*dy = 0;
		*dx = -1;
		break;
	}
}