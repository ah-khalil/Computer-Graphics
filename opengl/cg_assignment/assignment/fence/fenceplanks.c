#include "fenceplanks.h"

//function:	create_fenceplanks
//use:		creates the fence planks for use in the fence.c
void create_fenceplanks(GLfloat start_x, GLfloat start_z, GLfloat height, GLfloat width, GLuint texture_id) {
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	const GLfloat low_shininess = 5.0f;
	const GLfloat plank_depth = 0.125f;
	const GLfloat plank_height = 0.25f;
	
	glEnable(GL_LIGHTING);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, low_shininess);
	glColor3f(1.0f, 1.0f, 1.0f);

	//made in vertices instead of solid cubes in order to easily add textures
	glBegin(GL_QUAD_STRIP);
		//back (against the post)
		glNormal3f(-1.0, 0.0f, 0.0f);
		glTexCoord2f(20.0f, 20.0f); glVertex3f(plank_depth, height, 0.0f);
		glTexCoord2f(0.0f, 20.0f); glVertex3f(plank_depth, height - plank_height, 0.0f);
		glTexCoord2f(20.0f, 0.0f); glVertex3f(plank_depth, height, width);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(plank_depth, height - plank_height, width);
		
		//right
		glNormal3f(0.0, 0.0f, -1.0f);
		glTexCoord2f(20.0f, 20.0f); glVertex3f(plank_depth, height, 0.0f);
		glTexCoord2f(0.0f, 20.0f); glVertex3f(plank_depth, height - plank_height, 0.0f);
		glTexCoord2f(20.0f, 0.0f); glVertex3f(plank_depth * 2, height, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(plank_depth * 2, height - plank_height, 0.0f);

		//front (away from post)
		glNormal3f(1.0, 0.0f, 0.0f);
		glTexCoord2f(20.0f, 20.0f); glVertex3f(plank_depth * 2, height, 0.0f);
		glTexCoord2f(0.0f, 20.0f); glVertex3f(plank_depth * 2, height - plank_height, 0.0f);
		glTexCoord2f(20.0f, 0.0f); glVertex3f(plank_depth * 2, height, width);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(plank_depth * 2, height - plank_height, width);

		//left
		glNormal3f(0.0, 0.0f, 1.0f);
		glTexCoord2f(20.0f, 20.0f); glVertex3f(plank_depth * 2, height, width);
		glTexCoord2f(0.0f, 20.0f); glVertex3f(plank_depth * 2, height - plank_height, width);
		glTexCoord2f(20.0f, 0.0f); glVertex3f(plank_depth, height, width);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(plank_depth, height - plank_height, width);

		//top
		glNormal3f(0.0, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 20.0f); glVertex3f(plank_depth, height, 0.0f);
		glTexCoord2f(20.0f, 20.0f); glVertex3f(plank_depth * 2, height, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(plank_depth, height, width);
		glTexCoord2f(20.0f, 0.0f); glVertex3f(plank_depth * 2, height, width);

		//bottom
		glNormal3f(0.0, -1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(plank_depth, height - plank_height, 0.0f);
		glTexCoord2f(20.0f, 0.0f); glVertex3f(plank_depth * 2, height - plank_height, 0.0f);
		glTexCoord2f(20.0f, 20.0f); glVertex3f(plank_depth, height - plank_height, width);
		glTexCoord2f(0.0f, 20.0f); glVertex3f(plank_depth * 2, height - plank_height, width);
	glEnd();
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glDisable(GL_LIGHTING);
}