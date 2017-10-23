#ifndef VEC3F_H_INCLUDED
	#define VEC3F_H_INCLUDED
#endif // !VEC3F_H_INCLUDED

#include <stdio.h>
#include "bool.h"

typedef struct Vec3f {
	float v[3];
} Vec3f;

Vec3f* cross(Vec3f* vec_1, Vec3f* vec_2);

void reflect(Vec3f* vec);
void normalize(Vec3f* vec);
void scale(Vec3f* vec, float scale);
void vec_add(Vec3f* vec_1, Vec3f* vec_2);

float magnitude(Vec3f* vec);
float magnitude_squared(Vec3f* vec);
float dot(Vec3f* vec_1, Vec3f* vec_2);

boolean vec_to_file(FILE* file, Vec3f* vec);