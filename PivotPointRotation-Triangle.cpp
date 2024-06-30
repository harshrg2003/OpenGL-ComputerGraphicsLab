#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

float xp, yp; 
float td; 
float p[3][2] = { {-50, -50}, {50, -50}, {0, 50} }; 
int isRotated = 0; 

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
    glMatrixMode(GL_MODELVIEW);
}

void displayTriangle() {
    int i;

    glBegin(GL_TRIANGLES);
    for (i = 0; i < 3; i++) {
        glVertex2fv(p[i]);
    }
    glEnd();
}

void disp() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 1); // Blue color for the initial triangle
    displayTriangle();

    if (isRotated) {
        float x, y;
        float t = 3.142 / 180 * td;

        for (int i = 0; i < 3; i++) {
            x = p[i][0] * cos(t) - p[i][1] * sin(t) + xp * (1 - cos(t)) + yp * sin(t);
            y = p[i][0] * sin(t) + p[i][1] * cos(t) + yp * (1 - cos(t)) - xp * sin(t);
            p[i][0] = x;
            p[i][1] = y;
            printf("Vertex %d: (%.2f, %.2f)\n", i + 1, x, y);
        }

        glColor3f(0, 1, 0); // Green color for the rotated triangle
        displayTriangle();
    }

    glFlush();
}

void mouse(int b, int s, int x, int y) {
    if (s == GLUT_DOWN && !isRotated) {
        isRotated = 1;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("Triangle Rotation");
    init();

    printf("Enter the value of xp, yp, theta\n");
    scanf_s("%f%f%f", &xp, &yp, &td);

    glutDisplayFunc(disp);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}