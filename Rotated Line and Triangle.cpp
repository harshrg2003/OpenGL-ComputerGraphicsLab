#include <cmath>
#include <cstdio>
#include <GL/glut.h>

// Rotation angle
GLfloat angle;

// Function to initialize OpenGL settings
void myinit() {
    gluOrtho2D(-500, 500, -500, 500);
}

// Function to rotate a point around the origin
void rotatePoint(GLfloat& x, GLfloat& y, GLfloat angle) {
    GLfloat rad = angle * 3.14 / 180.0;
    GLfloat xNew = x * cos(rad) - y * sin(rad);
    GLfloat yNew = x * sin(rad) + y * cos(rad);
    x = xNew;
    y = yNew;
}

// Function to display the original and rotated line and triangle
void display() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // Original line
    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(-100, -100);
    glVertex2f(100, 100);
    glEnd();

    // Original triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(50, -50);
    glVertex2f(150, 50);
    glVertex2f(50, 150);
    glEnd();

    // Rotated line
    GLfloat x1 = -100, y1 = -100;
    GLfloat x2 = 100, y2 = 100;
    rotatePoint(x1, y1, angle);
    rotatePoint(x2, y2, angle);
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    // Rotated triangle
    GLfloat x3 = 50, y3 = -50;
    GLfloat x4 = 150, y4 = 50;
    GLfloat x5 = 50, y5 = 150;
    rotatePoint(x3, y3, angle);
    rotatePoint(x4, y4, angle);
    rotatePoint(x5, y5, angle);
    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glVertex2f(x5, y5);
    glEnd();

    glFlush();
}

// Main function
int main(int argc, char** argv) {
    printf("Enter the rotation angle (in degrees): ");
    scanf_s("%f", &angle);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotation of Line and Triangle");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
