#include<iostream>
#include<GL/glut.h>
float x = 35.0;
float y = 35.0;
float sizef = 10;
float red = 1.0, green = 1.0, blue = 1.0;
void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red, green, blue);
	glBegin(GL_QUADS);
	glVertex2f(x - sizef, y - sizef);
	glVertex2f(x + sizef, y - sizef);
	glVertex2f(x + sizef, y + sizef);
	glVertex2f(x - sizef, y + sizef);
	glEnd();
	glFlush();

}
void keyboard(unsigned char key, int x1, int y1) {
	switch (key) {

		case 'w':y += 25;
		         break;
		case 's':y -= 25;
			     break;
		case 'a':x -= 25;
			     break;
		case 'd':x += 25;
			     break;
		case '+':sizef += 5;
			     break;
		case '-':sizef -= 5;
			     break;
		case 'r':red = 1.0;
			     green = 0.0;
				 blue = 0.0;
				 break;
		case 'g':red = 0.0;
			     green = 1.0;
				 blue = 0.0;
				 break;
		case 'b':red = 0.0;
			     green = 0.0;
				 blue = 1.0;
				 break;
		case 'q':exit(0);


	}
	glutPostRedisplay();

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Keyboard Handling");
	gluOrtho2D(0, 500, 0, 500);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}