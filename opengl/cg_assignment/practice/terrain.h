#pragma once
#include "bool.h"
#include "Vec3f.h"

typedef struct Terrain {
	int width;					//width of terrain
	int length;					//length of terrain
	float** heights;			//different height values of terrain
	Vec3f** normals;			//terrain normals
	boolean computed_normals;	//are normals up-to-date?
} Terrain;