#include "globals.h"

void reshape(int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 201.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (x, y, z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}