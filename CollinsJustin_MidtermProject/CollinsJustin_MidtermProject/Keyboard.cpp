#include "globals.h"

void keyboard (unsigned char key, int x, int y)
{
	switch(key)
	{

	//Exit Orrary
	case 27:
		exit(0);
		break;

	//Pause Orrary
	case 'p':
	case 'P':
		if (pause == false)
		{
			pause = true;
			glutPostRedisplay();
		}
		else
		{
			pause = false;
			glutPostRedisplay();
		}
		break;

	case 'l':
	case 'L':
			launch = true;
		break;

	//Increases The Global Rotation Speed Of The Planets
	case '+':
	case '=':
		yearSpeed += .1;
		break;

	//Decreases The Global Roration Speed Of The Planets
	case '-':
	case '_':
		yearSpeed -= .1;
		break;

	//Resets The Global Rotation Speed Of The Planets
	case 'r':
	case 'R':
		yearSpeed = 5;
		break;
		
	default:
		break;
	}
}