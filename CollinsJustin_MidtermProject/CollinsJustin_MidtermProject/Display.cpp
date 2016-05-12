#include "globals.h"
#include "globals_light.h"
#include "Planets.h"

void display(void)
{
	GLfloat light_position0[] = {0.0, 0, 0.0, 1.0};
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Planet Loop
	glPushMatrix();
		
		//Sun Is Made
		glPushMatrix();
		glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
		makeSun(day);
		glPopMatrix();

		//Planet Mercury Is Rotated Around The Sun
		glPushMatrix();
		makeMercury(year, day);
		glPopMatrix();

		//Planet Venus Is Rotated Around The Sun
		glPushMatrix();
		makeVenus(year, day);
		glPopMatrix();

		//Planet Earth Is Rotated Around The Sun
		glPushMatrix();
		makeEarth(year, day);
		glPopMatrix();

		//Planet Mars Is Rotated Around The Sun
		glPushMatrix();
		makeMars(year, day);
		glPopMatrix();

		//Planet Jupiter Is Rotated Around The Sun
		glPushMatrix();
		makeJupiter(year, day);
		glPopMatrix();

		//Planet Saturn Is Rotated Around The Sun
		glPushMatrix();
		makeSaturn(year, day);
		glPopMatrix();

		//Planet Uranus Is Rotated Around The Sun
		glPushMatrix();
		makeUranus(year, day);
		glPopMatrix();

		//Planet Neptune Is Rotated Around The Sun
		glPushMatrix();
		makeNeptune(year, day);
		glPopMatrix();

	glPopMatrix();

	//Background Function Is Called
	glPushMatrix();
		makeBackground(day);
	glPopMatrix();

	glutSwapBuffers();
}