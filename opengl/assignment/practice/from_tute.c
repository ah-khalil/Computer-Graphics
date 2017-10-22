//Ali Khalil
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void init();
void draw();
void handle_keypress(unsigned char key, int x, int y);
void handle_resize(int width, int height);
void update(int value);

float _angle = 30;
float _camera_angle = 10;

int main(int argc, char** argv){
    //initialize glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);

    //create the window
    glutCreateWindow("Basic As Fuck Shapes");
    init();

    //handlers to handle drawing and different events (keypress, window resize)
    glutDisplayFunc(draw);
    glutKeyboardFunc(handle_keypress);
    glutReshapeFunc(handle_resize);
	glutTimerFunc(25, update, 0);			//calls the update() function every 25ms

    glutMainLoop();                         //loops main
    return 0;                               //so that the compiler doesn't yell at me
}

void init(){
    glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.7f, 0.9f, 1.0f, 1.0f);
}

void update(int value){
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();					//tells opengl to repaint the scene
	glutTimerFunc(25, update, 0);			//calls the update() function every 25ms
}

void handle_keypress(unsigned char key, int x, int y){
    switch (key) {
        case 27: //esc key
            exit(0);
    }
}

void handle_resize(int width, int height){
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

void draw(){
    //clear color buffer from last draw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);				//the drawing perspective
    glLoadIdentity();						//reset drawing perspective
	glRotatef(-_camera_angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -5.0f);		//set all objects to move -5z

	glPushMatrix();							//saves the current state of the matrix into the matrix stack
	glTranslatef(0.0f, -1.0f, 0.0f);		//this is applied to the matrix on top of the stack
	glRotatef(_angle, 0.0f, 0.0f, 1.0f);
	glScalef(0.7f, 0.7f, 0.7f);
	glColor3f(0.5f, 0.0f, 0.8f);

    glBegin(GL_QUADS);						//initiation of quad coordinates
        //trapezoid
        glVertex3f(-0.7f, -0.5f, 0.0f);
        glVertex3f(0.7f, -0.5f, 0.0f);
        glVertex3f(0.4f, 0.5f, 0.0f);
        glVertex3f(-0.4f, 0.5f, 0.0f);
        //end trapezoid
    glEnd();								//ends initiation of quad
	glPopMatrix();							//removes top matrix on stack

	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 0.0f);
	glRotatef(_angle, 1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLES);
        //pentagon
		glColor3f(1.0f, 0.75f, 0.5f);
        glVertex3f(-0.5f, -0.5f, 0.0f);

		glColor3f(0.9f, 0.15f, 0.1f);
        glVertex3f(0.5f, -0.5f, 0.0f);

		glColor3f(0.3f, 0.3f, 0.3f);
        glVertex3f(-0.5f, 0.0f, 0.0f);

		glColor3f(0.1f, 0.2f, 0.3f);
        glVertex3f(-0.5f, 0.0f, 0.0f);

		glColor3f(0.6f, 0.9f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);

		glColor3f(0.5f, 0.0f, 0.0f);
        glVertex3f(0.5f, 0.0f, 0.0f);

		glColor3f(0.7f, 0.45f, 0.32f);
        glVertex3f(-0.5f, 0.0f, 0.0f);

		glColor3f(0.1f, 0.2f, 0.4f);
        glVertex3f(0.5f, 0.0f, 0.0f);

		glColor3f(0.3f, 0.7f, 0.4f);
        glVertex3f(0.0f, 0.5f, 0.0f);
        //end pentagon
	glEnd();
	glPopMatrix();

	glTranslatef(-1.0f, 1.0f, 0.0f);
	glRotatef(_angle, 1.0f, 2.0f, 3.0f);
	glBegin(GL_TRIANGLES);
        //triangle
        glVertex3f(0.5f, -0.5f, 0.0f);
        glVertex3f(0.0f, 0.5f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);
		//end triangle
    glEnd();

    glutSwapBuffers();						//used for when using double buffers,
											//swaps rendering buffer with drawing buffer

}
