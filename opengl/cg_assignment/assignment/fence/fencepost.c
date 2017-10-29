#include "fencepost.h"

//function:	create_fencepost
//use:		creates the fence posts for use in the fence.c file
void create_fencepost(GLfloat start_x, GLfloat start_z, GLfloat height, GLuint texture_id) {
	GLfloat no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	const GLfloat high_shininess = 100.0f;
	const GLfloat fence_length = 0.125f;
	const GLfloat fence_start_y = 0.0f;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, high_shininess);
	glBegin(GL_QUAD_STRIP);
		//base of fence post
		glVertex3f(start_x, fence_start_y, start_z);
		glVertex3f(start_x, fence_start_y, start_z - fence_length);
		glVertex3f(start_x + fence_length, fence_start_y, start_z);
		glVertex3f(start_x + fence_length, fence_start_y, start_z - fence_length);

		//fencepost front
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(start_x, fence_start_y, start_z);
		glTexCoord2f(2.0f, 0.0f);  glVertex3f(start_x + fence_length, fence_start_y, start_z);
		glTexCoord2f(0.0f, 2.0f);  glVertex3f(start_x, height, start_z);
		glTexCoord2f(2.0f, 2.0f);  glVertex3f(start_x + fence_length, height, start_z);

		//fencepost left
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(start_x, fence_start_y, start_z);
		glTexCoord2f(2.0f, 0.0f);  glVertex3f(start_x, fence_start_y, start_z - fence_length);
		glTexCoord2f(0.0f, 2.0f);  glVertex3f(start_x, height, start_z);
		glTexCoord2f(2.0f, 2.0f);  glVertex3f(start_x, height, start_z - fence_length);

		//fencepost back
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(start_x, fence_start_y, start_z - fence_length);
		glTexCoord2f(2.0f, 0.0f);  glVertex3f(start_x + fence_length, fence_start_y, start_z - fence_length);
		glTexCoord2f(0.0f, 2.0f);  glVertex3f(start_x, height, start_z - fence_length);
		glTexCoord2f(2.0f, 2.0f);  glVertex3f(start_x + fence_length, height, start_z - fence_length);

		//fencepost right
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f);  glVertex3f(start_x + fence_length, fence_start_y, start_z - fence_length);
		glTexCoord2f(2.0f, 0.0f);  glVertex3f(start_x + fence_length, fence_start_y, start_z);
		glTexCoord2f(0.0f, 2.0f);  glVertex3f(start_x + fence_length, height, start_z - fence_length);
		glTexCoord2f(2.0f, 2.0f);  glVertex3f(start_x + fence_length, height, start_z);
	glEnd();
}
