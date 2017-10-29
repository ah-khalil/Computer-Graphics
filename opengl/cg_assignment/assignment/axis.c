#include "axis.h"

//function: create_axis
//use:		creates the axis to be used to test the positioning of objects in the world
void create_axis() {
	glPushMatrix();

	glBegin(GL_LINES);
		//x-line (red)
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(LINE_DISTANCE, 0.0f, 0.0f);
		glVertex3f(-LINE_DISTANCE, 0.0f, 0.0f);

		//y-line (green)
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, LINE_DISTANCE, 0.0f);
		glVertex3f(0.0f, -LINE_DISTANCE, 0.0f);

		//z-line (blue)
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, LINE_DISTANCE);
		glVertex3f(0.0f, 0.0f, -LINE_DISTANCE);
	glEnd();

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glPopMatrix();
}