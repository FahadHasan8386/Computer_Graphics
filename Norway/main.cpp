#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    /// Red background
    glColor3f(0.8, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(500,0);
        glVertex2f(500,350);
        glVertex2f(0,350);
    glEnd();

    /// White vertical
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex2f(136,0);
        glVertex2f(227,0);
        glVertex2f(227,350);
        glVertex2f(136,350);
    glEnd();

    /// White horizontal
    glBegin(GL_QUADS);
        glVertex2f(0,131);
        glVertex2f(500,131);
        glVertex2f(500,219);
        glVertex2f(0,219);
    glEnd();

    /// Blue vertical
    glColor3f(0.0,0.0,0.6);
    glBegin(GL_QUADS);
        glVertex2f(159,0);
        glVertex2f(204,0);
        glVertex2f(204,350);
        glVertex2f(159,350);
    glEnd();

    /// Blue horizontal
    glBegin(GL_QUADS);
        glVertex2f(0,153);
        glVertex2f(500,153);
        glVertex2f(500,197);
        glVertex2f(0,197);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    gluOrtho2D(0,500,0,350);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,350);
    glutCreateWindow("Norway Flag");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
