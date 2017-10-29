#include "main.h"

//function: main
//use:		kickstarts the program, calls the draw and update functions
int main(int argc, char** argv) {
	//initialize glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1920, 1080);

	//create the window
	glutCreateWindow("Australian Outback");
	init();

	//handlers to handle drawing and different events (keypress, window resize)
	glutDisplayFunc(draw);
	glutKeyboardFunc(handle_keypress);
	glutReshapeFunc(handle_resize);
	glutTimerFunc(10, update, 0);

	glutMainLoop();                         //loops main
	return 0;                               //so that the compiler doesn't yell at me
}

//function:	init
//use:		initializes the lights and enables various features, such as fog and lighting
void init() {
	GLfloat ambient_light[] = { 0.3f, 0.3f, 0.3f, 0.6f };

	GLfloat light_pos[] = { 15.0f, 15.0f, 15.0f, 1.0 };		//first light
	GLfloat ambience[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat diffuse[] = { 0.3f, 0.4f, 0.3f, 2.0f };
	GLfloat specular[] = { 7.0f, 1.0f, 2.0f, 5.0f };

	GLfloat light_pos_two[] = { -100.0f, 100.0f, -3.0f, 1.0 };	//second light
	GLfloat ambience_two[] = { 0.0f, 0.0f, 0.2f, 1.0f };
	GLfloat diffuse_two[] = { 0.3f, 1.0f, 1.0f, 1.0f };
	GLfloat specular_two[] = { 0.5f, 1.0f, 0.5f, 1.0f };

	//enables lighting and lighting related features
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_SHADE_MODEL);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_FOG);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambience);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	glLightfv(GL_LIGHT1, GL_POSITION, light_pos_two);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambience_two);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse_two);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular_two);

	//texture bitmaps
	terrain_texture = load_GLtextures("textures/dirt_big.bmp");
	fence_texture = load_GLtextures("textures/wood_fence.BMP");
	plank_texture = load_GLtextures("textures/birch.bmp");
	sheet_texture = load_GLtextures("textures/metal.bmp");
	box_texture = load_GLtextures("textures/crate.bmp");
	ausflag_texture = load_GLtextures("textures/australia_flag.bmp");
	tower_texture = load_GLtextures("textures/watertower_legs.bmp");

	x_angle = 0.0f;
	y_angle = 0.0f;
	rotate_x = 0.0f;
	rotate_y = 0.0f;
	zoom = 0.00f;
	anim_toggle = 0;
	zoom_lod = 0;
}

void reset(){
	x_angle = 0.0f;
	y_angle = 0.0f;
	rotate_x = 0.0f;
	rotate_y = 0.0f;
	zoom = 0.00f;
	anim_toggle = 0;
	flag_incr = 0.001f;
	zoom_lod = 0;
}

//function: update
//use:		this is called every 10ms and recalls the draw
void update(void) {
	flag_incr += 0.001f * anim_toggle;

	glutPostRedisplay();
	glutTimerFunc(10, update, 0);
}

//function:	hand_keypress
//use:		handles the key press inputs from the user
void handle_keypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //esc key
			exit(0);
			break;
		case 'A':
		case 'a':
			if (anim_toggle < 0.001f)
				anim_toggle = 1.0;
			break;
		case 'R':
		case 'r':
			reset();
			break;
		case 'F':
		case 'f':
			anim_toggle = (anim_toggle >= 0.001f) ? anim_toggle * 2.0f : 0.000f;
			break;
		case 'S':
		case 's':
			anim_toggle = (anim_toggle >= 0.001f) ? anim_toggle / 2 : 0.00f;
			break;
		case 'T':
		case 't':
			if (anim_toggle)
				anim_toggle = 0.0f;
			break;
		case 'C':
		case 'c':
			if (!anim_toggle)
				anim_toggle = 1.0f;
			break;
		case 'P':
			glShadeModel(GL_FLAT);
			break;
		case 'p':
			glShadeModel(GL_SMOOTH);
			break;
		case 'X':
		case 'x':
			rotate_x = (rotate_x == 0.0f) ? 1.0f : 0.0f;
			break;
		case 'Y':
		case 'y':
			rotate_y = (rotate_y == 0.0f) ? 1.0f : 0.0f;
			break;
		case 'Z':
			zoom = zoom + 0.1f;
			zoom_lod = zoom_lod + 1;
			break;
		case 'z':
			zoom = zoom - 0.1f;
			zoom_lod = zoom_lod - 1;
			break;
	}
}

//function:	draw_controls
//use:		draws the control text on the screen
void draw_controls(char* text, float x, float y) {
	glDisable(GL_FOG);
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glRasterPos2f(x, y);
	int j;
	for (j = 0; j < strlen(text); j++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[j]);
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_FOG);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
}

//function:	handle_resize
//use:		handles the resizing of the window
void handle_resize(int width, int height) {
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();                       //resets the objects to orig and faces them in -z
	gluPerspective(
		45.0,                               //camera angle
		(double)width / (double)height,     //width-to-height ratio
		1.0,                                //near z clipping plane (note: camera pointed at -z)
		200.0                               //far z clipping plane (note: camera pointed at -z)
	);
}

//function:	load_GLtextures
//use:		load bitmaps and convert to textures
GLuint load_GLtextures(char* filename) {
	GLuint texture_id = loadBMP_custom(filename);

	if (texture_id < 0) {
		printf("Could not find specified image");
		exit(1);
	}

	return texture_id;
}

//function:	draw
//use:		called by the main to draw the objects onto the screen
void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glFogfv(GL_FOG_COLOR, fog_color);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, 0.03f);

	//sets the camera "position" so that the objects are clearly visible on screen
	gluLookAt(
		7.0, 1.0, 7.0,
		-20.0, 10.0, -20.0,
		8.0, 4.0, 8.0
	);

	if (rotate_x == 1)
		x_angle += 0.1f;
	if (rotate_y == 1)
		y_angle += 0.1f;

	//sets the world scale and rotation based on the zoom and rotate vars
	glScalef(1.0f + zoom, 1.0f + zoom, 1.0f + zoom);
	glRotatef(x_angle, 0.0f, 1.0f, 0.0f);
	glRotatef(y_angle, 1.0f, 0.0f, 0.0f);

	create_terrain(terrain_texture);
	create_axis();
	create_box(0.0f, 0.0f, 0.0f, 2.0f, box_texture);
	create_fence(0.0f, 0.0f, 2.0f, 2.0f, fence_texture, plank_texture, sheet_texture);
	create_teapot(2.0f, 2.35f, -0.5f, 0.5f);
	create_flag(-5.0f, -1.0f, 0.0f, 0.1f, 10.0f, flag_incr, ausflag_texture, zoom_lod);
	create_watertower(-5.0f, -1.0f, -5.0f, 0.3f, 6.0f, tower_texture, zoom_lod);

	glPushMatrix();
	int i;
	for (i = 0; i < CONTROL_TEXT_LENGTH; i++) {
		draw_controls(controls[i], 1.0f, 1.0f - (i * 0.1f));
	}
	glPopMatrix();

	glutSwapBuffers();
}
