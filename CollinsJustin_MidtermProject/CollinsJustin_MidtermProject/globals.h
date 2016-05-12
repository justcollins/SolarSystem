#include "oglplatform.h"
#include "glm.h"

//Variables Defined For mySphere.c And render_planet.c
#define X_AXIS 0
#define Y_AXIS 1
#define Z_AXIS 2
#define PI 3.1415926

#define WIREFRAME 1
#define FLAT 3
#define SMOOTH 0
#define POINTS 2

#define P_ROW 180
#define P_COL 90

void mySphere(void);
void render_planet(void);

#ifdef MAIN

GLMmodel* pmodel = NULL;
char* pmodelMat = NULL;

float year = 0;
float day = 0;
float yearSpeed = 5;
float daySpeed = 2;
float satLaunch = 0;
bool launch = false;
bool pause = true;

float x = 0.0;
float y = 20.0;
float z = 49.0;

//A List Of Texture So Textures Can Be Loaded Into openGl
int texture[11];

float planetPoints[P_ROW][P_COL][3];

//Textures Are Loaded Into A List, Later To Be Combined With The List Of Texture
char const *planet_list[] =
{
	"../planets/earthcyl1.jpg",
    "../planets/moonmercator.jpg",
    "../planets/venusmap.jpg",
    "../planets/saturnmap.jpg",
    "../planets/uranuscyl1.jpg",
    "../planets/neptune.jpg",
	"../planets/sun_text.jpg",
	"../planets/stars.png",
	"../planets/Mars.jpg",
	"../planets/jupitermap.jpg",
	"../planets/mercury.jpg",
	"../planets/SnipperSnapper.jpg"
};

#else

extern GLMmodel* pmodel;

extern char* pmodelMat;

extern float year;

extern float day;

extern float yearSpeed;

extern float daySpeed;

extern float satLaunch;

extern bool launch;

extern bool pause;

extern float x;

extern float y;

extern float z;

extern int texture[];

extern float planetPoints[P_ROW][P_COL][3];

extern char const *planet_list[];

#endif