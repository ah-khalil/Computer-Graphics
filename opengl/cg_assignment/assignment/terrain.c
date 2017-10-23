#include "terrain.h"

void create_terrain(GLuint texture_id) {
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glEnable(GL_TEXTURE_2D);
	glPushMatrix();

	glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(0, 1);
		glVertex2f(1, 1);
		glVertex2f(1, 0);
	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}