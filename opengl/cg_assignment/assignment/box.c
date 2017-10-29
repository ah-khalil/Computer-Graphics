#include "box.h"

//function:	create_box
//use:		creates a box with a wooden texture surface
void create_box(GLfloat start_x, GLfloat start_y, GLfloat start_z, GLfloat size, GLuint texture_id) {
	GLfloat no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	const GLfloat high_shininess = 100.0f;

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);

	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, high_shininess);

	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPushMatrix();

	glTranslatef((size / 2.0) + 0.5, 0.0f, 0.0f);

	//texture and normal coordinates done in QUADS
	glBegin(GL_QUADS);
		//Front
		glNormal3f(0.0f, 0.0f, 1.0f);

		glTexCoord2f(0.0f, 0.0f); glVertex3f(start_x, start_y, start_z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(size, start_y, start_z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, start_z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(start_x, size, start_z);

		//Right
		glNormal3f(1.0f, 0.0f, 0.0f);

		glTexCoord2f(0.0f, 0.0f); glVertex3f(size, start_y, start_z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(size, start_y, -size);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, -size);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(size, size, start_z);

		//Back
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(size, start_y, -size);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(start_x, start_y, -size);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(start_x, size, -size);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(size, size, -size);

		//Left
		glNormal3f(-1.0f, 0.0f, 0.0f);

		glTexCoord2f(0.0f, 0.0f); glVertex3f(start_x, start_y, start_z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(start_x, start_y, -size);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(start_x, size, -size);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(start_x, size, start_z);
	glEnd();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_COLOR_MATERIAL);
}
