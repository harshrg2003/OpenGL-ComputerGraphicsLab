#include <cstdio>
#include <GL/glut.h>

// Scaling factors
GLfloat sx, sy;
GLfloat tx = 200, ty = 200;

// Function to initialize OpenGL settings
void myinit() {
    gluOrtho2D(-500, 500, -500, 500);
}

// Function to display the original and scaled polygon
void display() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // Original polygon vertices
    GLfloat vertices[][2] = {
        {-100, -100},
        {100, -100},
        {150, 0},
        {100, 100},
        {-100, 100},
        {-150, 0}
    };
    int numVertices = 6;

    // Original polygon
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; ++i) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();

    // Scaled polygon
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; ++i) {
        glVertex2f(vertices[i][0] * sx + tx, vertices[i][1] * sy + ty);

    }
    glEnd();

    glFlush();
}
void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        gluOrtho2D(-500.0, 500.0, -500.0 * (GLfloat)h / (GLfloat)w, 500.0 * (GLfloat)h / (GLfloat)w);
    else
        gluOrtho2D(-500.0 * (GLfloat)w / (GLfloat)h, 500.0 * (GLfloat)w / (GLfloat)h, -500.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Main function
int main(int argc, char** argv) {
    printf("Enter scaling factor for x (sx): ");
    scanf_s("%f", &sx);
    printf("Enter scaling factor for y (sy): ");
    scanf_s("%f", &sy);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scaling a Polygon");
    myinit();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
