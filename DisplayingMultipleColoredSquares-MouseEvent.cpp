#include <cstdlib> // For rand() and srand()
#include <ctime> 
#include<stdio.h>// For time()
#include <GL/glut.h>

struct Square {
    float x, y;
    unsigned char r, g, b;
};

Square squares[100];
int squareCount = 0;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0, 800, 0, 600);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    for (int i = 0; i < squareCount; ++i) {
        glColor3ub(squares[i].r, squares[i].g, squares[i].b);
        glBegin(GL_POLYGON);
        glVertex2f(squares[i].x - 25, squares[i].y - 25);
        glVertex2f(squares[i].x + 25, squares[i].y - 25);
        glVertex2f(squares[i].x + 25, squares[i].y + 25);
        glVertex2f(squares[i].x - 25, squares[i].y + 25);
        glEnd();
    }
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (squareCount < 100) {
            squares[squareCount].x = x;
            squares[squareCount].y = 600 - y;
            squares[squareCount].r = rand() % 256;
            squares[squareCount].g = rand() % 256;
            squares[squareCount].b = rand() % 256;
            squareCount++;
            printf("%d %d %d", squares[squareCount].r, squares[squareCount].g, squares[squareCount].b);
            glutPostRedisplay();
        }
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        squareCount = 0;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Random Colored Squares");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
