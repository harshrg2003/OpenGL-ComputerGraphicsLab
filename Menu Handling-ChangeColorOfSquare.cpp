#include<stdlib.h>
#include<GL/glut.h>

float red = 1.0, green = 1.0, blue = 1.0;
void display() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red, green, blue);
	glBegin(GL_QUADS);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);
	glEnd();
	glFlush();

}

void menu(int option) {
	switch (option) {

		case 1:red = 1.0;
			   green = 0.0;
		       blue = 0.0;
		       break;

		case 3:red = 0.0;
			   green = 1.0;
			   blue = 0.0;
			   break;

		case 2:red = 0.0;
			   green = 0.0;
			   blue = 1.0;
			   break;

		case 4:exit(0);

	}
	glutPostRedisplay();
}
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Menu Handling-Changing color of square");
	init();
	glutDisplayFunc(display);
	glutCreateMenu(menu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Blue", 2);
	glutAddMenuEntry("Green", 3);
	glutAddMenuEntry("Exit", 4);
	glutAttachMenu(GLUT_LEFT_BUTTON);
	
	glutMainLoop();
}