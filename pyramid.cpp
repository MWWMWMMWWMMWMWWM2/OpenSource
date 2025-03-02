#include <GL/glut.h>
#include <cmath>

// Lighting and shading setup
void initLighting() {
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; // Light position
    GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };  // Ambient light
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };  // Diffuse light

    glEnable(GL_LIGHTING); // Enable lighting
    glEnable(GL_LIGHT0);   // Enable light source 0

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
    glEnable(GL_COLOR_MATERIAL); // Enable color tracking for materials
}

// Draw the square pyramid
void drawPyramid() {
    // Base of the pyramid (square)
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glEnd();

    // Sides of the pyramid (triangles)
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0); // Blue
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(0.0, 1.0, 0.0);

    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(0.0, 1.0, 0.0);

    glColor3f(0.0, 1.0, 1.0); // Cyan
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(0.0, 1.0, 0.0);

    glColor3f(1.0, 1.0, 0.0); // Yellow
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(0.0, 1.0, 0.0);
    glEnd();
}

// Display callback function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear buffers
    glLoadIdentity(); // Reset transformations

    // Set camera position and orientation
    gluLookAt(4.0, 3.0, 4.0,  // Camera position (adjusted to show the bottom square)
              0.0, 0.0, 0.0,  // Look-at point
              0.0, 1.0, 0.0); // Up direction

    // Rotate the pyramid slightly to make the bottom square visible
    glRotatef(15.0, 1.0, 0.0, 0.0); // Rotate around the X-axis
    glRotatef(30.0, 0.0, 1.0, 0.0); // Rotate around the Y-axis

    drawPyramid(); // Draw the pyramid

    glutSwapBuffers(); // Swap buffers for smooth rendering
}

// Reshape callback function
void reshape(int width, int height) {
    glViewport(0, 0, width, height); // Set viewport
    glMatrixMode(GL_PROJECTION); // Switch to projection matrix
    glLoadIdentity(); // Reset projection matrix
    gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0); // Set perspective
    glMatrixMode(GL_MODELVIEW); // Switch back to modelview matrix
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set display mode
    glutInitWindowSize(800, 600); // Set window size
    glutCreateWindow("3D Square Pyramid with Shading"); // Create window

    initLighting(); // Initialize lighting

    glutDisplayFunc(display); // Register display callback
    glutReshapeFunc(reshape); // Register reshape callback

    glutMainLoop(); // Enter main loop
    return 0;
}