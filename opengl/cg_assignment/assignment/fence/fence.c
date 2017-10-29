#include "fence.h"

//function: create_fence
//use:		creates a fence using a fences subcomponents and places them together
void create_fence(GLfloat start_x, GLfloat start_z, GLfloat height, GLfloat width, GLuint fencepost_id, GLuint fenceplank_id, GLuint fencesheet_id) {
	const int post_num = 8;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, fencepost_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//create 8 of the fence posts (the vertical posts)
	size_t i;
	for (i = 0; i < post_num; i++)
	{
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, (i * 2.0f));
		create_fencepost(start_x, start_z, height, fencepost_id);
		glPopMatrix();
	}
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, fenceplank_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//create 2 of the fence planks (the horizontal planks on the fence)
	for (i = 0; i < 2; i++)
	{
		glPushMatrix();
		glTranslatef(0.0f, -(i * 0.66f), 0.0f);
		create_fenceplanks(start_x, start_z, height, width * post_num - 2, fenceplank_id);
		glPopMatrix();
	}
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, fencesheet_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//create 7 of the metallic sheets seen at the bottom of the fence
	for (i = 0; i < 7; i++)
	{
		glPushMatrix();
		glTranslatef(0.125f / 2, 0.0f, (i * 2.0f));
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(1.0f, 1.0f, 1.0f);
		create_fencesheets(height, fencesheet_id);
		glPopMatrix();
	}

	glDisable(GL_TEXTURE_2D);

	//create 8 of the vertical bars atop the fence
	for (i = 0; i < 8; i++) {
		glPushMatrix();
		glTranslatef(0.125f / 2, height, (i * 2.0f) - 0.125f / 2);
		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
		create_fenceshortbars();
		glPopMatrix();
	}
	//create 7 of the horizontal bars joining the shortbars together
	for (i = 0; i < 7; i++) {
		glPushMatrix();
		glTranslatef(0.125f/ 2, height + 0.5f, (i * 2.0f) - 0.125f / 2);
		create_fencelongbars(width);
		glPopMatrix();
	}
}
