#include "teapot.h"

//function:	create_teapot
//use:		creates a teapot to be drawn to the screen
void create_teapot(GLfloat pos_x, GLfloat pos_y, GLfloat pos_z, GLfloat size) {
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat high_shininess = 100.0f;

	glPushMatrix();
	glTranslatef(pos_x, pos_y, pos_z);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, high_shininess);
	
	glutSolidTeapot(size);

	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
	glPopMatrix();
}