#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    ///Bottom Green
    glColor3f(0,0.6,0);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(600,0);
        glVertex2f(600,150);
        glVertex2f(0,150);
    glEnd();

    ///Middle White
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glVertex2f(0,150);
        glVertex2f(600,150);
        glVertex2f(600,300);
        glVertex2f(0,300);
    glEnd();

    ///Top Black
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(0,300);
        glVertex2f(600,300);
        glVertex2f(600,450);
        glVertex2f(0,450);
    glEnd();

    ///Red Triangle
    glColor3f(0.8,0,0);
    glBegin(GL_TRIANGLES);
        glVertex2f(0,0);
        glVertex2f(0,450);
        glVertex2f(200,225);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    gluOrtho2D(0,600,0,450);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,450);
    glutCreateWindow("Palestine Flag , We loved Palestine.");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
