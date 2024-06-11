#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;


void setpixel(int x, int y)
{
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();

}
inline int Round(float a)
{
	return (int)a + 0.5;
}
void lineDDA()

{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	int x0 = 50, y0 = 50, xend = 250, yend = 250;
	int dx = xend - x0, dy = yend - y0, steps, k;
	float xincr, yincr, x = x0, y = y0;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xincr = dx / steps;
	yincr = dy / steps;

	setpixel(Round(x), Round(y));
	for (k = 0; k < steps; k++)
	{
		x += xincr;
		y += yincr;
		setpixel(Round(x), Round(y));
	}
	glFlush();
}


void myinit()
{
	gluOrtho2D(0, 500, 0, 500);
}


int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("DDA LINE DRAWING ALGORITHM");
	myinit();
	glutDisplayFunc(lineDDA);
	glutMainLoop();
}