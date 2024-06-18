#include <GL/glut.h>
#include <cstdio>

// Translation values
GLfloat tx, ty;

// Function to initialize OpenGL settings
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glColor3f(0.0, 0.0, 0.0);         
    glPointSize(10.0);                 
    glLineWidth(2.0);                 
    glMatrixMode(GL_PROJECTION);      
    gluOrtho2D(-200.0, 200.0, -200.0, 200.0); 
}

// Function to draw a point
void drawPoint(GLfloat x, GLfloat y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

// Function to draw a line
void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Function to draw a triangle
void drawTriangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3) {
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw original structures
    glColor3f(0.0, 0.0, 0.0); // Black color
    drawPoint(-80.0, 25.0);
    drawLine(-110.0, -110.0, 110.0, 110.0);
    drawTriangle(-30.0, -30.0, 0.0, 30.0, 30.0, -30.0);

    // Draw translated structures
    glColor3f(1.0, 0.0, 0.0); // Red color
    drawPoint(-80.0 + tx, 25.0 + ty);
    drawLine(-110.0 + tx, -110.0 + ty, 110.0 + tx, 110.0 + ty);
    drawTriangle(-30.0 + tx, -30.0 + ty, 0.0 + tx, 30.0 + ty, 30.0 + tx, -30.0 + ty);

    glFlush();
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
    glutCreateWindow("Translation of Point, Line, and Triangle");

    init();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
