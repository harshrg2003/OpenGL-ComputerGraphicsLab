#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>

float vertices[3][2] = {
	{0.0,0.5},
	{-0.5,-0.5},
	{0.5,-0.5}
};
float tx = 0.0, ty = 0.0;
float sx = 1.0, sy = 1.0;
float angle = 0.0;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		float x = vertices[i][0];
		float y = vertices[i][1];

		x *= sx;
		y *= sy;

		float rad = angle * 3.141 / 180.0;
		float x_rot = x * cos(rad) - y * sin(rad);
		float y_rot = x * sin(rad) + y * cos(rad);
		x = x_rot;
		y = y_rot;

		x += tx;
		y += ty;

		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':ty += 0.1;
		     break;
	case 's':ty -= 0.1;
		     break;
	case 'a':tx -= 0.1;
		     break;
	case 'd':tx += 0.1;
		     break;
	case '+':sx += 0.1;
		     sy += 0.1;
			 if (sx > 2.0) {
				 sx = 2.0;
			 }
			 if (sy > 2.0) {
				 sy = 2.0;
			 }
			 break;
	case '-':sx -= 0.1;
		     sy -= 0.1;
			 if (sx < 0.1) {
				 sx = 0.1;
			 }
			 if (sy < 0.1) {
				 sy = 0.1;
			 }
			 break;
	case 'r':angle += 5.0;
		     break;
	case 'i':angle -= 5.0;
		     break;
	case 27:exit(0);

	}
	glutPostRedisplay();
}
void reshape(int width, int height) {
	if (height == 0) {
		height = 1;
	}
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height) {
		gluOrtho2D(-1.0 * width / height, 1.0 * width / height, -1.0, 1.0);
	}
	else {
		gluOrtho2D(-1.0, 1.0, -1.0 * height / width, 1.0 * height / width);
	}
	glMatrixMode(GL_MODELVIEW);
}
void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("2D Transformations-Translation,Scaling,Rotation");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}