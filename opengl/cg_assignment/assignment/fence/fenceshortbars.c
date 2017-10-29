#include "fenceshortbars.h"

//function:	create_fenceshortbars
//use:		creates the fence vertical bars on top of the fence for use in the fence.c file
void create_fenceshortbars() {
	GLfloat mat_diffuse[] = { 0.1f, 0.1f, 0.1f, 0.1f };
	GLfloat mat_specular[] = { 0.0f, 1.0f, 2.0f, 1.0f };
	const GLfloat high_shininess = 0.0f;
	GLUquadric* quad = gluNewQuadric();

	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, high_shininess);

	gluCylinder(quad, 0.1f, 0.1f, 0.5f, 12, 12);

	glDisable(GL_COLOR_MATERIAL);
}
