#pragma once
#include <GL/glut.h>

//testing materials
GLfloat no_mat[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_ambient_color[] = { 0.8f, 0.8f, 0.2f, 1.0f };
GLfloat mat_diffuse[] = { 0.1f, 0.5f, 0.8f, 1.0f };
GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat mat_emission[] = { 0.3f, 0.2f, 0.2f, 0.0f };
const GLfloat no_shininess = 0.0f;
const GLfloat low_shininess = 5.0f;
const GLfloat high_shininess = 100.0f;