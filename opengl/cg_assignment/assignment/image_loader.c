#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "image.h"

// quick and dirty bitmap loader...for 24 bit bitmaps with 1 plane only.  
// See http://www.dcs.ed.ac.uk/~mxr/gfx/2d/BMP.txt for more info.

int ImageLoad(char *filename, Image *image) {
	FILE *file;
	FILE *file_2;
	unsigned long size;                 // size of the image in bytes.
	unsigned long i;                    // standard counter.
	unsigned short int planes;          // number of planes in image (must be 1) 
	unsigned short int bpp;             // number of bits per pixel (must be 24)
	char temp;                          // temporary color storage for bgr-rgb conversion.

	if ((file_2 = fopen("assignment//debug.txt", "w+")) == NULL) {
		return 0;
	}

	if ((file = fopen(filename, "rb")) == NULL)
	{
		fprintf(file_2, "File Not Found : %s\n", filename);
		return 0;
	}

	// seek through the bmp header, up to the width/height:
	fseek(file, 18, SEEK_CUR);

	// read the width
	if ((i = fread(&image->width, 4, 1, file)) != 1) {
		fprintf(file_2, "Error reading width from %s.\n", filename);
		return 0;
	}
	fprintf(file_2, "Width of %s: %lu\n", filename, image->width);

	// read the height 
	if ((i = fread(&image->height, 4, 1, file)) != 1) {
		fprintf(file_2, "Error reading height from %s.\n", filename);
		return 0;
	}
	fprintf(file_2, "Height of %s: %lu\n", filename, image->height);

	// calculate the size (assuming 24 bits or 3 bytes per pixel).
	size = image->width * image->height * 3;

	fprintf(file_2, "Size of image: %lu\n", size);

	// read the planes
	if ((fread(&planes, 2, 1, file)) != 1) {
		fprintf(file_2, "Error reading planes from %s.\n", filename);
		return 0;
	}
	if (planes != 1) {
		fprintf(file_2, "Planes from %s is not 1: %u\n", filename, planes);
		return 0;
	}

	fprintf(file_2, "Number of Planes: %lu\n", planes);

	// read the bpp
	if ((i = fread(&bpp, 2, 1, file)) != 1) {
		fprintf(file_2, "Error reading bpp from %s.\n", filename);
		return 0;
	}
	if (bpp != 24) {
		fprintf(file_2, "Bpp from %s is not 24: %u\n", filename, bpp);
		return 0;
	}

	fprintf(file_2, "Bits in Bitmap: %lu\n", bpp);

	// seek past the rest of the bitmap header.
	fseek(file, 24, SEEK_CUR);

	// read the data. 
	image->pixels = (char *)malloc(size);
	if (image->pixels == NULL) {
		fprintf(file_2, "Error allocating memory for color-corrected image data");
		return 0;
	}

	if ((i = fread(image->pixels, size, 1, file)) != 1) {
		fprintf(file_2, "Error reading image data from %s.\n", filename);
		return 0;
	}

	for (i = 0; i<size; i += 3) { // reverse all of the colors. (bgr -> rgb)
		temp = image->pixels[i];
		image->pixels[i] = image->pixels[i + 2];
		image->pixels[i + 2] = temp;
	}

	// we're done.
	return 1;
}

