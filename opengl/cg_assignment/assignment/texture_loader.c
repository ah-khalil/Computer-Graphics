#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "texture_loader.h"

//http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/

//function:	loadBMP_custom
//use:		loads and verifies a bitmap to be used a texture
GLuint loadBMP_custom(const char * imagepath) {
	GLuint texture_id;
	FILE* file = fopen(imagepath, "rb");

	unsigned char header[54];		// Each BMP file begins by a 54-bytes header
	unsigned int data_pos;			// Position in the file where the actual data begins
	unsigned int width, height;		// = width * height * 3
	unsigned int image_size;   
	unsigned char * data;			// Actual RGB data

	if (!file) {
		printf("Image could not be opened\n");
		return -1;
	}

	if (fread(header, 1, 54, file) != 54) {
		printf("Not a correct BMP file\n");
		return -1;
	}

	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP File\n");
		return -1;
	}

	data_pos	= *(int*)&(header[0x0A]);
	image_size	= *(int*)&(header[0x22]);
	width		= *(int*)&(header[0x12]);
	height		= *(int*)&(header[0x16]);

	if (image_size == 0)
		image_size = width * height * 3;

	if (data_pos == 0)
		data_pos = 54;

	data = (unsigned char*)malloc(image_size * sizeof(unsigned char));

	fread(data, 1, image_size, file);

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexImage2D(
		GL_TEXTURE_2D, 
		0, 
		GL_RGB, 
		width, 
		height, 
		0, 
		GL_BGR_EXT, 
		GL_UNSIGNED_BYTE, 
		data
	);

	fclose(file);

	return texture_id;
}