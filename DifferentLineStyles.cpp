#include <GL/glut.h>

// Initialize OpenGL Graphics
void init() {
    // Set the background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // Set up the 2D orthographic view
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

// Display callback function
void display() {
    // Clear the window with the background color
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color to black for drawing lines
    glColor3f(0.0, 0.0, 0.0);

    // Draw a solid line
    glBegin(GL_LINES);
    glVertex2f(50.0, 450.0);
    glVertex2f(450.0, 450.0);
    glEnd();

    // Enable line stippling for dashed line
    glEnable(GL_LINE_STIPPLE);
    // 0xFF01 pattern : dash and dot
    // 0xC0C0 Pattern: 1100000011000000 (two dots and a dash)
    glLineStipple(1, 0x00FF); // Dashed pattern: 0000000011111111
    glBegin(GL_LINES);
    glVertex2f(50.0, 350.0);
    glVertex2f(450.0, 350.0);
    glEnd();

    // Enable line stippling for dotted line
    glLineStipple(1, 0x0101); // Dotted pattern: 0000000100000001
    glBegin(GL_LINES);
    glVertex2f(50.0, 250.0);
    glVertex2f(450.0, 250.0);
    glEnd();

    // Disable line stippling to revert to solid lines for further drawing
    glDisable(GL_LINE_STIPPLE);

    // Flush the drawing to the window
    glFlush();
}


int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    // Set the initial display mode (single buffer and RGBA)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set the initial window position and size
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    // Create the window with a title
    glutCreateWindow("OpenGL Line Styles Example");

    // Call the initialization function
    init();

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();

    return 0;
}

