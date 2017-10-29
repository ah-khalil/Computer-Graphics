#include "terrain.h"

//function: create_terrain
//use:		creates the terrain to act as a floor
void create_terrain(GLuint texture_id) {
	GLfloat no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_emission[] = { 0.3f, 0.2f, 0.2f, 0.0f };
	const GLfloat low_shininess = 5.0f;
	
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glEnable(GL_TEXTURE_2D);
	glPushMatrix();

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

	//creates the normals and texture coordinates of the terrain
	glBegin(GL_QUADS);
		glNormal3f(0.0f, 1.0f, 0.0f);

		glTexCoord2f(10.0f, 0.0f); glVertex3f(-LENGTH, 0.0f, LENGTH);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(LENGTH, 0.0f, LENGTH);
		glTexCoord2f(0.0f, 10.0f); glVertex3f(LENGTH, 0.0f, -LENGTH);
		glTexCoord2f(10.0f, 10.0f); glVertex3f(-LENGTH, 0.0f, -LENGTH);
	glEnd();

	glPopMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
}