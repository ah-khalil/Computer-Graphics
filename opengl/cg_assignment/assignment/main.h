#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "image.h"
#include "terrain.h"

void init();
void draw(void);
void update(int value);
GLuint load_GLtextures(char* filename);
void handle_resize(int width, int height);
void handle_keypress(unsigned char key, int x, int y);