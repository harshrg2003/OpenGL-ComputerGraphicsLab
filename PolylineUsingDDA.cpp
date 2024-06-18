#include <GL/glut.h>
#include <cmath>

const int MAX_POINTS = 100;
int pointsX[MAX_POINTS];
int pointsY[MAX_POINTS];
int pointCount = 0;

// DDA line drawing algorithm
void drawDDALine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; ++i) {
        glVertex2i(x, y);
        x += xIncrement;
        y += yIncrement;
    }
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    
    for (int i = 0; i < pointCount - 1; ++i) {
        drawDDALine(pointsX[i], pointsY[i], pointsX[i + 1], pointsY[i + 1]);
    }

    glFlush();
}

// Mouse callback function
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Store the point
        if (pointCount < MAX_POINTS) {
            if (pointCount >= 2) {
                // Add new point to continue polyline from the last point
                pointsX[pointCount] = x;
                pointsY[pointCount] = 480 - y;  
                pointCount++;
            }
            else {
                // Add initial points
                pointsX[pointCount] = x;
                pointsY[pointCount] = 480 - y;  
                pointCount++;
            }

            
            glutPostRedisplay();
        }
    }
}

// Initialize OpenGL
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glColor3f(0.0, 0.0, 0.0); 
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("DDA Line Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}
