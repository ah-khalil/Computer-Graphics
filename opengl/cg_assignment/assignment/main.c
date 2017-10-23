#include "main.h"

int main(int argc, char** argv) {
	//initialize glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1920, 1080);

	//create the window
	glutCreateWindow("Australian Outback");
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
	/*glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);					//enable lighting
	glEnable(GL_LIGHT0);					//enable light #0
	glEnable(GL_LIGHT1);					//enable light #1
	glEnable(GL_NORMALIZE);*/					//normalize all normals
}

void update(int value) {

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
GLuint load_GLtextures(char* filename) {
	// Create Texture
	GLuint texture_id;
	Image* image = (Image *)malloc(sizeof(Image));						// allocate space for texture
	
	if (!ImageLoad(filename, image)) {
		printf("Could not find specified image");
		exit(1);
	}
	
	glGenTextures(1, &texture_id);										//make room for texture
	glBindTexture(GL_TEXTURE_2D, texture_id);							// 2d texture (x and y size)

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// scale linearly when image bigger than texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// scale linearly when image smalled than texture

	glTexImage2D(
		GL_TEXTURE_2D,													//2d texture
		0,																//level of detail 0 (normal)
		3,																//3 components (r,g,b)
		image->width,													//x size from image
		image->height,													//y size from image
		0,																//border 0 (normal)
		GL_RGB,															//rgb color data
		GL_UNSIGNED_BYTE,												//unsigned byte data
		image->pixels													//the data itself
	);

	return texture_id;
}

void draw() {
	GLuint terrain_texture = load_GLtextures("assignment//textures//crate.bmp");
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBindTexture(GL_TEXTURE_2D, terrain_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(30.0f, 1.0f, 0.0f, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glPushMatrix();

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-1, 1);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(1, 1);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(1, -1);
		glTexCoord2f(-1.0f, 0.0f); glVertex2f(-1, -1);
	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	//create_terrain(terrain_texture);

	glutSwapBuffers();
}