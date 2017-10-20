#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

void init();
void draw();
void handle_keypress(unsigned char key, int x, int y);
void handle_resize(int width, int height);

int main(int argc, char** argv){
    //initialize glut
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);

    //create the window
    glutCreateWindow("Basic As Fuck Shapes");
    init();

    //handlers to handle drawing and different events (keypress, window resize)
    glutDisplayFunc(draw);
    glutKeyboardFunc(handle_keypress);
    glutReshapeFunc(handle_resize);

    glutMainLoop();                         //loops main
    return 0;                               //so that the compiler doesn't yell at me
}

void init(){
    glEnable(GL_DEPTH_TEST);
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

    glMatrixMode(GL_MODELVIEW);     //the drawing perspective
    glLoadIdentity();               //reset drawing perspective

    glBegin(GL_QUADS);              //initiation of quad coordinates
        //trapezoid
        glVertex3f(-0.7f, -1.5f, -5.0f);
        glVertex3f(0.7f, -1.5f, -5.0f);
        glVertex3f(0.4f, -0.5f, -5.0f);
        glVertex3f(-0.4f, -0.5f, -5.0f);
        //end pentagon
    glEnd();                        //ends initiation of quad

    glBegin(GL_TRIANGLES);
        //pentagon
        glVertex3f(0.5f, 0.5f, -5.0f);
        glVertex3f(1.5f, 0.5f, -5.0f);
        glVertex3f(0.5f, 1.0f, -5.0f);

        glVertex3f(0.5f, 1.0f, -5.0f);
        glVertex3f(1.5f, 0.5f, -5.0f);
        glVertex3f(1.5f, 1.0f, -5.0f);

        glVertex3f(0.5f, 1.0f, -5.0f);
        glVertex3f(1.5f, 1.0f, -5.0f);
        glVertex3f(1.0f, 1.5f, -5.0f);
        //end pentagon

        //triangle
        glVertex3f(-0.5f, 0.5f, -5.0f);
        glVertex3f(-1.0f, 1.5f, -5.0f);
        glVertex3f(-1.5f, 0.5f, -5.0f);
    glEnd();

    glutSwapBuffers();              //used for when using double buffers,
                                    //swaps rendering buffer with drawing buffer

}
