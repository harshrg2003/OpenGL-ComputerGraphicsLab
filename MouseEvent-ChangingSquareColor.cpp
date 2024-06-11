#include<GL/glut.h>

void myinit()
{
	gluOrtho2D(-1, 1, -1, 1);
}

float red = 1.0, blue = 1.0, green = 1.0;

void display()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red, blue, green);
	glBegin(GL_QUADS);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);
	glEnd();
	glFlush();
}

void mymouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			red = 1.0;
			green = 0.0;
			blue = 0.0;
			break;
		case GLUT_RIGHT_BUTTON:
			red = 0.0;
			green = 0.0;
			blue = 1.0;
			break;
		case GLUT_MIDDLE_BUTTON:
			red = 0.0;
			green = 1.0;
			blue = 0.0;
			break;

		}
		glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Change Square Color");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mymouse);
	glutMainLoop();
}



