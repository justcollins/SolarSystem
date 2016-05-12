#include <stdlib.h>
#define MAIN
#include <stdio.h>
#include "globals.h"
#include "globals_light.h"
#include "Init.h"
#include "Display.h"
#include "Reshape.h"
#include "Keyboard.h"
#include "Animate.h"

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition (100, 100);
	glutCreateWindow(argv[0]);
	glutFullScreen();
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(animate);
	glutMainLoop();
	return 0;
}