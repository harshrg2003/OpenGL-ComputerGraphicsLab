#include <cstdio>
#include <GL/glut.h>

// Translation values
GLfloat tx, ty;

// Function to initialize OpenGL settings
void myinit() {
    gluOrtho2D(0, 1000, 0, 1000);
}

// Function to display the original and translated house
void display1() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // Original house
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(50, 50);
    glVertex2i(300, 50);
    glVertex2i(300, 350);
    glVertex2i(50, 350);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex2i(50, 350);
    glVertex2i(175, 600);
    glVertex2i(300, 350);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 1, 1);
    glVertex2i(150, 50);
    glVertex2i(150, 225);
    glVertex2i(200, 225);
    glVertex2i(200, 50);
    glEnd();

    // Translated house
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(50 + tx, 50 + ty);
    glVertex2i(300 + tx, 50 + ty);
    glVertex2i(300 + tx, 350 + ty);
    glVertex2i(50 + tx, 350 + ty);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    glVertex2i(50 + tx, 350 + ty);
    glVertex2i(175 + tx, 600 + ty);
    glVertex2i(300 + tx, 350 + ty);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 1);
    glVertex2i(150 + tx, 50 + ty);
    glVertex2i(150 + tx, 225 + ty);
    glVertex2i(200 + tx, 225 + ty);
    glVertex2i(200 + tx, 50 + ty);
    glEnd();

    glFlush();
}
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        gluOrtho2D(0.0, 1000.0, 0.0, 1000.0 * (GLfloat)h / (GLfloat)w);
    else
        gluOrtho2D(0.0, 1000.0 * (GLfloat)w / (GLfloat)h, 0.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Main function
int main(int argc, char** argv) {
    printf("Enter translation value for x: ");
    scanf_s("%f", &tx);
    printf("Enter translation value for y: ");
    scanf_s("%f", &ty);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Displaying house with translation");
    myinit();
    glutDisplayFunc(display1);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
