#include <windows.h>
#include <stdlib.h>
#include <GL/glut.h>

#define UNIT 0.25

float const vertex[8][3] = {
    {-UNIT, -UNIT, UNIT},
    {-UNIT, UNIT, UNIT},
    {UNIT, UNIT, UNIT},
    {UNIT, -UNIT, UNIT},
    {-UNIT, -UNIT, -UNIT},
    {-UNIT, UNIT, -UNIT},
    {UNIT, UNIT, -UNIT},
    {UNIT, -UNIT, -UNIT}
};

float _angle_x = 0.0;
float _angle_y = 0.0;

float tran_x = 0.5;
float tran_y = 0.5;

void win_init();
void on_key(unsigned char m_key, int x, int y);
void quad(int a, int b);
void mydisplay();
void move_angle_x();
void move_angle_y();

int main(int argc, char** argv){
    glutInit(&argc, argv);
    win_init();
    glutDisplayFunc(mydisplay);
    glutKeyboardFunc(on_key);

    glutMainLoop();
}

void quad(int a, int b){
    glBegin(GL_QUADS);
        glColor3f(0.1f, 0.0f, 0.4f);
        glVertex2f(-a,-b);
        glVertex2f(a,-b);
        glVertex2f(a,b);
        glVertex2f(-a,b);
    glEnd();
}

void move_angle_x(){
    _angle_x += 2.0f;

    if(_angle_x > 360.0f){
        _angle_x -+ 360.0f;
    }

    glutPostRedisplay();
}

void move_angle_y(){
    _angle_y += 2.0f;

    if(_angle_y > 360.0f){
        _angle_y -+ 360.0f;
    }

    glutPostRedisplay();
}

void on_key(unsigned char m_key, int x, int y){
    switch (m_key) {
        case 'Q':
        case 'q':
            exit(EXIT_SUCCESS);
            break;
        case 'y':
        case 'Y':
            move_angle_y();
            break;
        case 'x':
        case 'X':
            move_angle_x();
            break;
    }
}

void win_init(){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("simple");
}

void mydisplay(){
    int i;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION ); /*switch to the drawing perspective*/
    glLoadIdentity();   /*reset the drawing perspective*/

    /*as all the object in the scene are translated -0.5x units
    the position of the vertices, when being placed, would assume
    initial position of -0.5x, 0y, 0z*/

    /*the same applies when the whole scene is translated -0.25y
    units*/

    /*IMPORTANT POINT: glTranslatef moves the origin of the objects;
    when it comes to rotation, the objects will rotate about this new
    origin*/
    glRotatef(_angle_x, 1, 0, 0);
    glRotatef(_angle_y, 0, 1, 0);

    glTranslatef(0, -0.75, 0);

    glRotatef(80, 1, 0, 0);

    quad(1, 1);

    glFlush();
}
