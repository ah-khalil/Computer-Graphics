#include "fencesheets.h"

//function:	create_fencesheets
//use:		creates the fence sheets to be used in the fence.c file
void create_fencesheets(GLfloat height, GLuint texture_id) {
	GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat high_shininess = 100.0f;
	const GLfloat plank_depth = 0.125f;

	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, high_shininess);

	//creates the normals and texture coordinates in quad strip
	glBegin(GL_QUAD_STRIP);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(plank_depth, 0.0f);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(plank_depth, height / 2);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(-2.0f, 0.0f);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(-2.0f, height / 2);
	glEnd();

	glDisable(GL_COLOR_MATERIAL);
}
