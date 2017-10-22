#ifndef VEC3F_H_INCLUDED
	#define VEC3F_H_INCLUDED
#endif // !VEC3F_H_INCLUDED

#include <stdio.h>
#include "bool.h"

typedef struct Vec3f {
	float v[3];
} Vec3f;

Vec3f reflect(Vec3f** vec);
Vec3f normalize(Vec3f** vec);
Vec3f scale(Vec3f** vec, float scale);
Vec3f scale_set(Vec3f** vec, float scale);
Vec3f vec_scale(Vec3f** vec, float scale);
Vec3f cross(Vec3f** vec_1, Vec3f** vec_2);
Vec3f vec_add(Vec3f** vec_1, Vec3f** vec_2);
Vec3f vec_add_set(Vec3f** vec_1, Vec3f** vec_2);

float magnitude(Vec3f** vec);
float magnitude_squared(Vec3f** vec);
float get_idx(Vec3f** vec, int index);
float dot(Vec3f** vec_1, Vec3f** vec_2);

boolean vec_to_file(FILE* file, Vec3f** vec);