#pragma once
#include <GL/glut.h>

typedef struct Image {
	char* pixels;
	int width;
	int height;
}Image;


GLuint loadBMP_custom(const char * imagepath);
