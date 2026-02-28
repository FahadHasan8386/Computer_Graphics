#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    ///Green from bottom
    glColor3f(0.0, 0.42, 0.31);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(800, 0);
    glVertex2i(800, 100);
    glVertex2i(0, 100);
    glEnd();

    ///Yellow
    glColor3f(1.0, 0.84, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(0, 100);
    glVertex2i(800, 100);
    glVertex2i(800, 200);
    glVertex2i(0, 200);
    glEnd();

    ///Green
    glColor3f(0.0, 0.42, 0.31);
    glBegin(GL_QUADS);
    glVertex2i(0, 200);
    glVertex2i(800, 200);
    glVertex2i(800, 300);
    glVertex2i(0, 300);
    glEnd();

    ///Yellow
    glColor3f(1.0, 0.84, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(0, 300);
    glVertex2i(800, 300);
    glVertex2i(800, 400);
    glVertex2i(0, 400);
    glEnd();

    ///Green
    glColor3f(0.0, 0.42, 0.31);
    glBegin(GL_QUADS);
    glVertex2i(0, 400);
    glVertex2i(800, 400);
    glVertex2i(800, 500);
    glVertex2i(0, 500);
    glEnd();

    /// RED
    glColor3f(0.83, 0.06, 0.21);
    glBegin(GL_QUADS);
    glVertex2i(0, 200);
    glVertex2i(400, 200);
    glVertex2i(400, 500);
    glVertex2i(0, 500);
    glEnd();

   ///White
    glColor3f(1.0, 1.0, 1.0);

    /// Up ward polygon
    glBegin(GL_POLYGON);
        glVertex2i(200, 470);
        glVertex2i(80, 290);
        glVertex2i(200, 330);
        glVertex2i(320, 290);
    glEnd();

    /// Down ward triangle
    glBegin(GL_TRIANGLES);
        glVertex2i(50, 410);
        glVertex2i(350, 410);
        glVertex2i(200, 330);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Togo Flag");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
