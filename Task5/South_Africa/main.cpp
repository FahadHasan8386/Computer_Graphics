#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void init() {
    gluOrtho2D(0, 800, 0, 400);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    ///Green background
    glBegin(GL_POLYGON);
     glColor3f(0.0f, 0.478f, 0.216f);
        glVertex2i(0,0);
        glVertex2i(800,0);
        glVertex2i(800,400);
        glVertex2i(0,400);
    glEnd();

    ///Bottom white shape
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2i(96,0);
        glVertex2i(800,0);
        glVertex2i(800,160);
        glVertex2i(416,160);
    glEnd();

    ///Bottom blue shape
    glBegin(GL_POLYGON);
     glColor3f(0.0f, 0.259f, 0.510f);
        glVertex2i(160,0);
        glVertex2i(800,0);
        glVertex2i(800,134);
        glVertex2i(426,134);
    glEnd();

    ///Top white shape
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2i(96,400);
        glVertex2i(800,400);
        glVertex2i(800,240);
        glVertex2i(416,240);
    glEnd();

    ///Top red shape
    glBegin(GL_POLYGON);
     glColor3f(0.878f, 0.0f, 0.137f);
        glVertex2i(160,400);
        glVertex2i(800,400);
        glVertex2i(800,266);
        glVertex2i(426,266);
    glEnd();

    ///yellow triangle
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.722f, 0.0f);
        glVertex2i(0,48);
        glVertex2i(304,200);
        glVertex2i(0,352);
    glEnd();

    ///black triangle
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(0,80);
        glVertex2i(240,200);
        glVertex2i(0,320);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 400);
    glutInitWindowPosition(200, 100);

    glutCreateWindow("Africa Flag");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
