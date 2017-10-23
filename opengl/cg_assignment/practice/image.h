#pragma once

typedef struct Image {
	char* pixels;
	int width;
	int height;
}Image;

int ImageLoad(char *filename, Image *image);