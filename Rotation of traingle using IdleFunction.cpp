#include <GL/glut.h>


float angle = 0.0f;
bool RotationEnabled = false;

float vertices[3][2] = {
    { -0.5f, -0.5f },
    {  0.5f, -0.5f },
    {  0.0f,  0.5f }
};


void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

   
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (int i = 0; i < 3; ++i) {
        glVertex2fv(vertices[i]);
    }
    glEnd();

   

    glFlush();
}

// Idle callback function
void idle() {
    // Update the rotation angle
    if (RotationEnabled) {
        angle += 0.1f;
        if (angle > 360.0f) {
             angle -= 360.0f;
        }

    }

    // Redraw the scene
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !RotationEnabled) {
        RotationEnabled = true;
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        RotationEnabled = false;
    }
}

int main(int argc, char** argv) {
   
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotating Triangle-Using Idle function");

    
    init();

    
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);

   
    glutMainLoop();

    return 0;
}
