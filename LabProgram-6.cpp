#include<math.h>
#include<GL/glut.h>
float theta = 0;

bool rotationEnabled = false;

void init() {
	gluOrtho2D(-100, 100, -100, 100);
}
void idle() {
	if (rotationEnabled) {
		theta += 0.01;
		if (theta >= 360) {
			theta = 0;
		}
	}
	glutPostRedisplay();
}
void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h) gluOrtho2D(-100.0 * w / h, 100.0 * w / h, -100, 100);
	else gluOrtho2D(-100, 100, -100.0 * h / w, 100.0 * h / w);
	glMatrixMode(GL_MODELVIEW);
}
void disp() {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta, 0, 0, 1);
	glColor3f(0, 0, 1);
	
	glBegin(GL_POLYGON);
	glVertex2f(-50, -50);
	glVertex2f(50, -50);
	glVertex2f(50, 50);
	glVertex2f(-50, 50);
	glEnd();
	glutSwapBuffers();
}
void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		rotationEnabled = true;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		rotationEnabled = false;
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("Rotation Of square-Idle function");
	init();
	glutDisplayFunc(disp);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}
