#include "flag.h"

//function:	create_flag
//use:		creates the flag that will also be animated
void create_flag(GLfloat pos_x, GLfloat pos_y, GLfloat pos_z, GLfloat radius, GLfloat height, GLfloat incr, GLuint texture_id) {
	GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat no_shininess = 0.0f;
	const GLfloat high_shininess = 100.0f;
	GLfloat flag_alt = height - (radius * 2.0f) - 2.0f + pos_y;
	GLfloat flag_low = flag_alt;

	GLUquadric* quad = gluNewQuadric();

	glPushMatrix();

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, high_shininess);

	//the flagpole
	glTranslatef(pos_x, pos_y, pos_z);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
		gluCylinder(quad, radius, radius, height, 10, 10);
	glEnd();
	glPopMatrix();

	//the flag spherical top
	glPushMatrix();
	glTranslatef(pos_x, height + pos_y, pos_z);
	glBegin(GL_POLYGON);
		glutSolidSphere(radius * 2, 10, 10);
	glEnd();
	glPopMatrix();

	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//the flag
	glPushMatrix();

	glTranslatef(pos_x - 0.2, flag_alt - flag_low * sin(incr), pos_z);
	glRotatef(20.0, 0.0f, 1.0f, 0.0f);

	glBegin(GL_QUAD_STRIP);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 2.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(4.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(4.0f, 2.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
	glPopMatrix();
	gluDeleteQuadric(quad);

}