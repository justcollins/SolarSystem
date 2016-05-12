#include "Planets.h"
#include "globals.h"
#include "globals_light.h"

//Colors Defined For The Scene
GLfloat Yellow[] = {0.5, 0.5, 0.0, 1.0};
GLfloat OldGold [] = {0.81, 0.71, 0.23};

//Material Properties Defined For The Scene
GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
GLfloat low_specular[] = {0.5,0.5,0.5,1.0};
GLfloat high_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat no_shininess[] = {0.0};
GLfloat low_shininess[] = {5.0};
GLfloat high_shininess[] = {100.0};
GLfloat mat_emission[] = {0.3, 0.3, 0.3, 0.0};

void makeSun(float day)
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glMaterialfv(GL_FRONT, GL_AMBIENT, Yellow);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, Yellow);
		glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
		glMaterialfv(GL_FRONT, GL_SHININESS, high_specular);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission);
		glBindTexture(GL_TEXTURE_2D, texture[6]);
		glRotatef ((GLfloat) (day*0.07), 0.0, 1.0, 0.0);
		glRotatef(90,0.0,1.0,0.0);
		glRotatef(90,1.0,0.0,0.0);
		glScalef(4,4,4);
		render_planet();
		glDisable(GL_TEXTURE_2D);
	glPopAttrib();
	glPopMatrix();
}

void makeMercury(float year, float day)
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[10]);
		glRotatef ((GLfloat) (year*0.3575), 0.0, 1.0, 0.0);
		glTranslatef (10.0, 0.0, 0.0);
		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
		glRotatef(90,1.0,0.0,0.0);
		glScalef(1,1,1);
		render_planet();
		glDisable(GL_TEXTURE_2D);
	glPopAttrib();
	glPopMatrix();
}

void makeVenus(float year, float day)
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glRotatef ((GLfloat) (year*0.31), 0.0, 1.0, 0.0);
		glTranslatef (-15.0, 0.0, 0.0);
		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
		glRotatef(90,1.0,0.0,0.0);
		glScalef(1.5,1.5,1.5);
		render_planet();
		glDisable(GL_TEXTURE_2D);
	glPopAttrib();
	glPopMatrix();
}

void makeEarth(float year, float day)
{
	//Earth
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glRotatef ((GLfloat) (year*0.25), 0.0, 1.0, 0.0);
		glTranslatef (0.0, 0.0, 20.0);
		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
		glRotatef(-90,1.0,0.0,0.0);
		glScalef(1.5,1.5,1.5);
		render_planet();

			//model load
		glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
			glEnable(GL_TEXTURE_2D);
			glTranslatef(0,satLaunch,0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
			glRotatef(35,0.0,1.0,0.0);
			glRotatef(90, 1.0,0.0,0.0);
			glBindTexture(GL_TEXTURE_2D, texture[11]);
			glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
			glDisable(GL_TEXTURE_2D);
		glPopAttrib();
		glPopMatrix();

		//The Moon
		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texture[1]);
			glRotatef ((GLfloat) (year*0.75), 1.0, 0.0, 0.0);
			glTranslatef (2.0, 0.0, 0.0);
			glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
			glRotatef(90,1.0,0.0,0.0);
			glScalef(0.3,0.3,0.3);
			render_planet();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
	glPopAttrib();
	glPopMatrix();
}

void makeMars(float year, float day)
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[8]);
		glRotatef ((GLfloat) (year*0.207), 0.0, 1.0, 0.0);
		glTranslatef (0.0, 0.0, -25.0);
		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
		glRotatef(90,1.0,0.0,0.0);
		glScalef(1.1,1.1,1.1);
		render_planet();
		glDisable(GL_TEXTURE_2D);
	glPopAttrib();
	glPopMatrix();
}

void makeJupiter(float year, float day)
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[9]);
		glRotatef ((GLfloat) (year*0.187), 0.0, 1.0, 0.0);
		glTranslatef (29.0, 0.0, 0.0);
		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
		glRotatef(90,1.0,0.0,0.0);
		glScalef(2.5,2.5,2.5);
		render_planet();
		glDisable(GL_TEXTURE_2D);
	glPopAttrib();
	glPopMatrix();
}

void makeSaturn(float year, float day)
{
	//Planet
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glRotatef ((GLfloat) (year*0.155), 0.0, 1.0, 0.0);
		glTranslatef (-35.0, 0.0, 0.0);
		glScalef(2.2,2.2,2.2);
		glRotatef(90,1.0,0.0,0.0);
		glRotatef ((GLfloat) day, 0.0, 0.0, -1.0);
		render_planet();

		//Ring
		glPushMatrix();
			glMaterialfv(GL_FRONT, GL_AMBIENT, OldGold);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, OldGold);
			glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
			glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
			glScalef(1.0, 1.0, 0.2);
			glutSolidTorus((1.05 * .3), (1.05 * 1.5), 25, 25);
		glPopMatrix();
		
		glDisable(GL_TEXTURE_2D);
	glPopAttrib();
	glPopMatrix();

}

void makeUranus(float year, float day)
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glRotatef ((GLfloat) (year*0.112), 0.0, 1.0, 0.0);
		glTranslatef (0.0, 0.0, 43.0);
		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
		glRotatef(90,1.0,0.0,0.0);
		glScalef(1.8,1.8,1.8);
		render_planet();
		glDisable(GL_TEXTURE_2D);
	glPopAttrib();
	glPopMatrix();
}

void makeNeptune(float year, float day)
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glRotatef ((GLfloat) (year*0.025), 0.0, 1.0, 0.0);
		glTranslatef (0.0, 0.0, -46.0);
		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
		glRotatef(90,1.0,0.0,0.0);
		glScalef(1.8,1.8,1.8);
		render_planet();
		glDisable(GL_TEXTURE_2D);
	glPopAttrib();
	glPopMatrix();
}

void makeBackground(float day)
{
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);
		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture[7]);
		glRotatef ((GLfloat) (day*-0.02), 0.0, 1.0, 0.0);
		glRotatef(90,-1.0,0.0,0.0);
		glScalef(100,100,100);
		render_planet();
		glDisable(GL_TEXTURE_2D);
	glPopAttrib();
	glPopMatrix();
}