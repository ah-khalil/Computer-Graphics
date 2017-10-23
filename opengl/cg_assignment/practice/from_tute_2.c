//Ali Khalil
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "image.h"

void init();
void draw(void);
GLuint load_GLtextures();
void update(int value);
void handle_resize(int width, int height);
void handle_keypress(unsigned char key, int x, int y);

GLuint texture_id;
float _angle = 30;
float _camera_angle = 10;

int main(int argc, char** argv) {
	//initialize glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1920, 1080);

	//create the window
	glutCreateWindow("Basic As Fuck Shapes 2: Electric Boogaloo");
	init();

	//handlers to handle drawing and different events (keypress, window resize)
	glutDisplayFunc(draw);
	glutKeyboardFunc(handle_keypress);
	glutReshapeFunc(handle_resize);
	glutTimerFunc(25, update, 0);			//calls the update() function every 25ms

	glutMainLoop();                         //loops main
	return 0;                               //so that the compiler doesn't yell at me
}

void init() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);					//enable lighting
	glEnable(GL_LIGHT0);					//enable light #0
	glEnable(GL_LIGHT1);					//enable light #1
	glEnable(GL_NORMALIZE);					//normalize all normals
	//glShadeModel(GL_SMOOTH);				//enable smooth shading

	load_GLtextures();
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();					//tells opengl to repaint the scene
	glutTimerFunc(25, update, 0);			//calls the update() function every 25ms
}

void handle_keypress(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //esc key
		exit(0);
	}
}

void handle_resize(int width, int height) {
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();                       //resets the objects to orig and faces them in -z
	gluPerspective(
		45.0,                               //camera angle
		(double)width / (double)height,     //width-to-height ratio
		1.0,                                //near z clipping plane (note: camera pointed at -z)
		200.0                               //far z clipping plane (note: camera pointed at -z)
	);
}

// Load Bitmaps And Convert To Textures
GLuint load_GLtextures() {
	Image* image1 = (Image *)malloc(sizeof(Image));						// allocate space for texture
	GLuint texture_id;

	if (image1 == NULL) {
		printf("Error allocating space for image");
		exit(1);
	}

	if (!ImageLoad("textures/crate.bmp", image1)) {
		printf("Could not find specified image");
		exit(1);
	}

	// Create Texture	
	glGenTextures(1, &texture_id);										//make room for texture
	glBindTexture(GL_TEXTURE_2D, texture_id);							// 2d texture (x and y size)

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// scale linearly when image smalled than texture

	glTexImage2D(
		GL_TEXTURE_2D,													//2d texture
		0,																//level of detail 0 (normal)
		3,																//3 components (r,g,b)
		image1->width,													//x size from image
		image1->height,													//y size from image
		0,																//border 0 (normal)
		GL_RGB,															//rgb color data
		GL_UNSIGNED_BYTE,												//unsigned byte data
		image1->pixels													//the data itself
	);

	free(image1);

	return texture_id;
}

void draw(void) {
	GLfloat ambient_color[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat light_color0[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat light_pos0[] = { -10.0f, 15.0f, 20.0f, 0.0f };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_color);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos0);

	glTranslatef(0.0f, 0.0f, -8.0f);
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);	// scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);	// scale linearly when image smalled than texture
	glColor3f(1.0f, 0.6f, 0.3f);
	
	glBegin(GL_QUADS);
		//Front
		//glNormal3f(0.0f, 0.0f, 1.0f);
		
		glNormal3f(-1.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.5f, -1.0f, 1.5f);

		glNormal3f(1.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1.5f, -1.0f, 1.5f);

		glNormal3f(1.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(1.5f, 1.0f, 1.5f);

		glNormal3f(-1.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.5f, 1.0f, 1.5f);

		//Right
		//glNormal3f(1.0f, 0.0f, 0.0f);
		
		glNormal3f(1.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.5f, -1.0f, 1.5f);

		glNormal3f(1.0f, 0.0f, -1.0f);
		glTexCoord2f(2.0f, 0.0f); glVertex3f(1.5f, -1.0f, -1.5f);

		glNormal3f(1.0f, 0.0f, 1.0f);
		glTexCoord2f(2.0f, 2.0f); glVertex3f(1.5f, 1.0f, -1.5f);

		glNormal3f(1.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 2.0f); glVertex3f(1.5f, 1.0f, 1.5f);

		//Back
		//glNormal3f(0.0f, 0.0f, -1.0f);

		glNormal3f(-1.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(1.5f, -1.0f, -1.5f);

		glNormal3f(-1.0f, 0.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.5f, -1.0f, -1.5f);

		glNormal3f(1.0f, 0.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.5f, 1.0f, -1.5f);

		glNormal3f(1.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(1.5f, 1.0f, -1.5f);

		//Left
		//glNormal3f(0.0f, 0.0f, -1.0f);

		glNormal3f(-1.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.5f, -1.0f, 1.5f);

		glNormal3f(-1.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.5f, -1.0f, -1.5f);

		glNormal3f(-1.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.5f, 1.0f, -1.5f);

		glNormal3f(-1.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.5f, 1.0f, 1.5f);
	glEnd();

	//glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();						//used for when using double buffers,
											//swaps rendering buffer with drawing buffer
}
