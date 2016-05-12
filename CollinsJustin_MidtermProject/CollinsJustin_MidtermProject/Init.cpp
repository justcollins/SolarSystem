#include <string>
#include <iostream>

#include "globals.h"
#include "SOIL.h"
#include "globals_light.h"

using namespace std;

void init(void)
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	for (int i = 0; i < 12; i++)
	{
		texture[i] = SOIL_load_OGL_texture(planet_list[i], 4, 0, SOIL_FLAG_MIPMAPS);
		cout << i << endl;
	}

	pmodel = glmReadOBJ("../model/Satellite.obj");

	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 100);
	glmScale(pmodel, 0.5);
	glmLinearTexture(pmodel);

	mySphere();
}