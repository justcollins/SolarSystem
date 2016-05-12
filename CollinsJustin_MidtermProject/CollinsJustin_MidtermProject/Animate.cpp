#include "globals.h"

void animate(void)
{
	if (pause == true)
	{
		if(launch)
		{
			satLaunch += 0.01;
		}
		if(satLaunch >= 2.0)
		{
			launch = false;
			satLaunch = 2.0;
		}

		year += yearSpeed;
		day += daySpeed;
		glutPostRedisplay();
	}
}