#include "fencelongbars.h"

//function:	create_fencelongbars
//use:		creates the longbars on a fence for use in the fence.c file
void create_fencelongbars(GLfloat width) {
	GLfloat mat_diffuse[] = { 0.5f, 0.4f, 0.1f, 1.0f };
	GLfloat mat_specular[] = { 0.1f, 0.1f, 0.1f, 0.1f };
	const GLfloat high_shininess = 100.0f;
	GLUquadric* quad = gluNewQuadric();

	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, high_shininess);

	gluCylinder(quad, 0.1f, 0.1f, width, 12, 12);

	glDisable(GL_COLOR_MATERIAL);
}
