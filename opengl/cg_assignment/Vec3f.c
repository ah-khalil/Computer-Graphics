#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Vec3f.h"

Vec3f* reflect(Vec3f* vec) {
	vec->v[0] = -1 * vec->v[0];
	vec->v[1] = -1 * vec->v[1];
	vec->v[2] = -1 * vec->v[2];

	return vec;
}

Vec3f* normalize(Vec3f* vec) {
	float m = magnitude(vec);

	vec->v[0] = vec->v[0] / m;
	vec->v[1] = vec->v[1] / m;
	vec->v[2] = vec->v[2] / m;

	return vec;
}

Vec3f* scale(Vec3f* vec, float scale) {
	vec->v[0] *= scale;
	vec->v[1] *= scale;
	vec->v[2] *= scale;

	return vec;
}

Vec3f* cross(Vec3f* vec_1, Vec3f* vec_2) {
	Vec3f* ret_vec = (Vec3f*)malloc(sizeof(Vec3f));

	ret_vec->v[0] = vec_1->v[1] * vec_2->v[2] - vec_1->v[2] * vec_2->v[1];
	ret_vec->v[1] = vec_1->v[2] * vec_2->v[0] - vec_1->v[0] * vec_2->v[2];
	ret_vec->v[2] = vec_1->v[0] * vec_2->v[1] - vec_1->v[1] * vec_2->v[0];

	return ret_vec;
}

Vec3f* vec_add(Vec3f* vec_1, Vec3f* vec_2) {
	vec_1->v[0] += vec_2->v[0];
	vec_1->v[1] += vec_2->v[1];
	vec_1->v[2] += vec_2->v[2];

	return vec_1;
}

float magnitude(Vec3f* vec) {
	float m = sqrt(
		vec->v[0] * vec->v[0] +
		vec->v[1] * vec->v[1] +
		vec->v[2] + vec->v[2]
	);

	return m;
}

float magnitude_squared(Vec3f* vec) {
	return (vec->v[0] * vec->v[0] + vec->v[1] * vec->v[1] + vec->v[2] + vec->v[2]);
}

float dot(Vec3f* vec_1, Vec3f* vec_2) {
	return vec_1->v[0] * vec_2->v[0] + vec_1->v[1] * vec_2->v[1] + vec_1->v[2] * vec_2->v[2];
}

boolean vec_to_file(FILE* file, Vec3f* vec) {
	if (fprintf(file, "Vec[0]: %f\nVec[1]: %f\nVec[2]: %f\n", vec->v[0], vec->v[1], vec->v[2]) < 0)
		return false;
	return true;
}