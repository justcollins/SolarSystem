#include "oglplatform.h"
#include "globals.h"
//#include "globals_light.h"

void render_planet(void)
{
	extern float planetPoints[P_ROW][P_COL][3];

	int ix, iy;
	int jx, jy;	// jy = ix + 1
	

	
	float texleft, texbottom, textop, texright;
	
	static int test = 0;
	ix = 0;
	iy = 0;
	
	//if(render_type == POINTS) glBegin(GL_POINTS);
	//if(render_type == WIREFRAME) glBegin(GL_POLYGON);
	//if(render_type == FLAT) {/*glDisable(GL_TEXTURE_2D);*/glShadeModel(GL_SMOOTH);glBegin(GL_QUADS);}
	//if(render_type == SMOOTH) {/*glEnable(GL_TEXTURE_2D);*/glShadeModel(GL_SMOOTH);glBegin(GL_QUADS);}
	
//printf("rc %d     %d %d %d %d\n",planet_select, row,col,row_count,col_count);
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


