//#include "oglplatform.h"

#include <math.h>

#include "globals.h"
//#include "globals_sun_moon.h"
//#include "globals_planet2.h"
#include "globals_light.h"

extern float planetPoints[P_ROW][P_COL][3];

void mySphere(void)
{
	//extern float planetPoints[P_ROW][P_COL][3];

	int i,j,k;
	
	float	pi;
	float	alpha,beta;
	float	calpha,cbeta;
	float	dalpha,dbeta;
	float	xalpha,zalpha;
	float	xbeta,ybeta,zbeta;
	float	radian;
	float	x,y,z;
	
	int ix, iy;
	
	
	
		pi = 3.1415926;
		radian = pi/180.0;
		
		dalpha = 180.0 / ((float) P_COL - 1.0);
		dbeta = 360.0 / ((float) P_ROW -1.0);
		
    //fprintf(stderr,"function mySphere\n");


	for(ix = 0, beta = 0.0; ix < P_ROW; ix++)
	{
		for(iy = 0, alpha = 90.0; iy < P_COL; iy++)
		{
			
				xalpha = cos(alpha * radian);
				zalpha = sin(alpha * radian);
				xbeta = xalpha * cos(beta * radian);
				ybeta = xalpha * sin(beta * radian);
			
			planetPoints[ix][iy][X_AXIS] = xbeta * 5.0;
			planetPoints[ix][iy][Y_AXIS] = ybeta * 5.0;
			
			
			planetPoints[ix][iy][Z_AXIS] = zalpha * 5.0;
			
			alpha = alpha - dalpha;
			
			

			
		}
		beta = beta + dbeta;
	} 
}

