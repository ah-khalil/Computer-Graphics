#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "fence/fence.h"
#include "terrain.h"
#include "box.h"
#include "teapot.h"
#include "flag.h"
#include "watertower.h"
#include "axis.h"
#include "texture_loader.h"

#define CONTROL_TEXT_LENGTH 13

void init(void);
void draw(void);
void update(void);
void draw_controls(char* text, float x, float y);
GLuint load_GLtextures(char* filename);
void handle_resize(int width, int height);
void handle_keypress(unsigned char key, int x, int y);
void reset();

//vars for textures
GLuint terrain_texture;
GLuint fence_texture;
GLuint plank_texture;
GLuint sheet_texture;
GLuint box_texture;
GLuint ausflag_texture;
GLuint tower_texture;

//vars for controls
GLfloat zoom;
GLfloat rotate_x;
GLfloat rotate_y;
GLfloat anim_toggle;
int zoom_lod;

//global transformation
GLfloat x_angle;
GLfloat y_angle;

//controls text
const char *controls[CONTROL_TEXT_LENGTH] = {
	"======Controls:======",
	"<A>/<a> : Start Animation",
	"<F>/<f> : Faster Animation",
	"<S>/<s> : Slower Animation",
	"<T>/<t> : Pause Animation",
	"<C>/<c> : Resume Animation",
	"<P> : Flat-Shade Polygonization",
	"<p> : Smooth-Shade Polygonization",
	"<X>/<x> : Rotate X",
	"<Y>/<y> : Rotate Y",
	"<Z> : Zoom In",
	"<z> : Zoom Out",
	"====================="
};

//vars for fog
GLfloat fog_color[] = {0.9f, 0.6f, 0.3f, 1};

//vars for animation
GLfloat flag_incr = 0.001f;
