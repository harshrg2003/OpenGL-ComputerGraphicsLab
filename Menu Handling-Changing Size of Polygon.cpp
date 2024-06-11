#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

int w = 640, h = 480;
int sizef = 0;
void init() {
	gluOrtho2D(0, w, 0, h);
}

void display() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(250 - sizef, 250 - sizef);
	glVertex2f(350 + sizef, 250 - sizef);
	glVertex2f(350 + sizef, 350 + sizef);
	glVertex2f(250 - sizef, 350 + sizef);
	glEnd();
	glFlush();
}
void d_menu(int op) {
	if (op == 1) {
		sizef += 5;
	}
	else if (op == 2) {
		sizef -= 5;
	}
	else if (op == 3) {
		sizef = 0;
	}
	else if (op == 4) {
		exit(0);
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("Menu Handling-Changing size of polygon");
	init();
	glutCreateMenu(d_menu);
	glutAddMenuEntry("Increase", 1);
	glutAddMenuEntry("Decrease", 2);
	glutAddMenuEntry("Refresh", 3);
	glutAddMenuEntry("Quit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
	glutMainLoop();
}