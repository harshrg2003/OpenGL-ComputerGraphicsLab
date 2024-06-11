#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
float xStart, xEnd, yStart, yEnd;
int count = 1;
inline int round(float x) {
	return (int)x + 0.5;
}
void init() {
	gluOrtho2D(0, 500, 0, 500);
}
void setpixel(int x,int y) {
	glColor3f(1, 1, 1);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
	glFlush();
}
void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	int dx = xEnd - xStart;
	int dy = yEnd - yStart;
	int k;
	float xincrement=0.0, yincrement=0.0, x = xStart, y = yStart, steps;
	if (fabs(dx) > fabs(dy)) {
		steps = fabs(dx);
	}
	else {
		steps = fabs(dy);
	}
	if (steps > 0) {
	xincrement = dx / steps;
	yincrement = dy / steps;
	}
	setpixel(round(x), round(y));
	for (k = 0; k < steps; k++) {
		x += xincrement;
		y += yincrement;
		setpixel(round(x), round(y));
	}
	glFlush();
}
void mymouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		if (count == 1) {
			xStart = x;
			yStart = 500-y;

			xEnd = x;
			yEnd = 500 - y;
			count++;
		}else {
			xEnd = x;
			yEnd = 500-y;
			glutPostRedisplay();
			count = 1;
		}
	printf("%d.%d__%f,%f,%f,%f\n", button,state,xStart, yStart, xEnd, yEnd);
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Keyboard Handling");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mymouse);
	glutMainLoop();
}


