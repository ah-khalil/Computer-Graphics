#include "watertower.h"

//function:	create_watertower
//use:		creates the watertower, drawn into the scene
void create_watertower(GLfloat pos_x, GLfloat pos_y, GLfloat pos_z, GLfloat radius, GLfloat height, GLuint texture_id) {
	GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	const GLfloat high_shininess = 100.0f;
	GLUquadric* quad = gluNewQuadric();
	GLfloat radius_mul = 5.0f;

	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, high_shininess);

	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	gluQuadricTexture(quad, GL_TRUE);

	//the leg of the watertower
	glTranslatef(pos_x, pos_y, pos_z);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
		gluCylinder(quad, radius, radius, height, 10, 10);
	glEnd();
	glPopMatrix();
	gluQuadricTexture(quad, GL_FALSE);

	//the base of the water tank
	glPushMatrix();
	glTranslatef(pos_x, height + pos_y, pos_z);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	
	glBegin(GL_POLYGON);
		for (double i = 0; i < 2 * PI; i += PI / 12) {
				glVertex3f(cos(i) * (radius * radius_mul), (sin(i) * radius * radius_mul), 0.0);
		}
	glEnd();
	glPopMatrix();

	//the water tank
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(pos_x, height + 2.0f + pos_y, pos_z);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
		gluCylinder(quad, radius * radius_mul, radius * radius_mul, 2.0f, 10, 10);
	glEnd();
	glPopMatrix();

	//the roof of the water tank
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(pos_x, height + 1.55f + pos_y, pos_z);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

	glutSolidCone(radius * radius_mul + 0.5f, 2.0f, 12, 12);

	gluDeleteQuadric(quad);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glDisable(GL_COLOR_MATERIAL);
}