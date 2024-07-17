#include<cmath>
#include<Gl/glut.h>


void setpixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void myinit()
{
	gluOrtho2D(0, 500, 0, 500);
}


void linebresenhams(int x0, int y0, int xend, int yend)
{
	int dx = fabs(xend - x0);
	int dy = fabs(yend - y0);
	int p = 2 * (dy)-dx;
	int twody = 2 * dy;
	int twodyminusdx = 2 * (dy - dx);
	int x, y;

	if (x0 > xend)
	{
		x = xend;
		y = yend;
		xend = x0;

	}
	else
	{
		x = x0;
		y = y0;
	}
	setpixel(x, y);

	while (x < xend)
	{
		x++;
		if (p < 0)
		{
			p = p + twody;
		}
		else
		{
			y++;
			p = p + twodyminusdx;
		}
		setpixel(x, y);
	}

}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	int x0 = 50, y0 = 100;
	int xend = 200, yend = 300;
	linebresenhams(x0, y0, xend, yend);
	glFlush();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("BRESENHAM'S LINE DRAWING");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}



