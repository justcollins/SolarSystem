#include "globals.h"

void render_planet(void)
{
	int ix, iy;
	int jx, jy;
	
	float texleft, texbottom, textop, texright;
	
	static int test = 0;
	ix = 0;
	iy = 0;
	
	glEnable(GL_TEXTURE_2D);glShadeModel(GL_SMOOTH);

	glBegin(GL_QUADS);

	for(ix = 0; ix < P_ROW - 1; ix++)
	{		
		for(iy = 0; iy < P_COL - 1; iy++)
		{			
			texleft 	= (float) ix / (float) P_ROW;
			texbottom	= (float) iy / ((float) P_COL - 2.0) ;
			texright	= (float) (ix+1) / (float) P_ROW;
			textop		= (float) (iy+1) / ((float) P_COL - 2.0) ;			
			
			jx = ix + 1;	jy = iy + 1;
			
			glNormal3f( planetPoints[ix][iy][X_AXIS],planetPoints[ix][iy][Y_AXIS],planetPoints[ix][iy][Z_AXIS]);
			
			glTexCoord2f(texleft, texbottom);
			glVertex3f( planetPoints[ix][iy][X_AXIS],planetPoints[ix][iy][Y_AXIS],planetPoints[ix][iy][Z_AXIS]);
			
			glTexCoord2f(texleft, textop);
			glVertex3f( planetPoints[ix][jy][X_AXIS],planetPoints[ix][jy][Y_AXIS],planetPoints[ix][jy][Z_AXIS]);
			
			glTexCoord2f(texright, textop);
			glVertex3f( planetPoints[jx][jy][X_AXIS],planetPoints[jx][jy][Y_AXIS],planetPoints[jx][jy][Z_AXIS]);
			
			glTexCoord2f(texright, texbottom);
			glVertex3f( planetPoints[jx][iy][X_AXIS],planetPoints[jx][iy][Y_AXIS],planetPoints[jx][iy][Z_AXIS]);
		}
	}
	glEnd();
}