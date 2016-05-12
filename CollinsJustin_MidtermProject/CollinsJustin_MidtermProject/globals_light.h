#ifdef MAIN

GLfloat ambient[] = {0.1, 0.1, 0.1, 1.0};
GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat mat_shininess[] = {50.0};
GLfloat light_position0[] = {0.0, 0.0, 0.0, 1.0};
GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};
GLfloat lmodel_ambient[] = {0.0, 0.0, 0.0, 1.0};

#else

extern GLfloat ambient[];
extern GLfloat diffuse[];
extern GLfloat mat_specular[];
extern GLfloat mat_shininess[];
extern GLfloat light_position0[];
extern GLfloat white_light[];
extern GLfloat lmodel_ambient[];

#endif