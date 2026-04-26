#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>

float cloudMove = 0.0f;

/// circle
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 40; i++) {
        float a = 2 * 3.1416 * i / 40;
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
    }
    glEnd();
}

/// SKY
void sky() {
    glColor3ub(135, 206, 250);
    glBegin(GL_QUADS);
    glVertex2f(0, 15);
    glVertex2f(25, 15);
    glVertex2f(25, 10);
    glVertex2f(0, 10);
    glEnd();
}

/// SUN
void sun() {
    glColor3ub(255, 200, 0);
    drawCircle(3, 13.5, 0.7);
}

/// CLOUD
void cloud() {
    glPushMatrix();
    glTranslatef(cloudMove, 0, 0);

    glColor3ub(255, 255, 255);
    drawCircle(6, 13, 0.6);
    drawCircle(7, 13.3, 0.6);
    drawCircle(8, 13, 0.6);

    glPopMatrix();
}

/// GROUND
void ground() {
    glColor3ub(200, 230, 150);
    glBegin(GL_QUADS);
    glVertex2f(0, 10);
    glVertex2f(25, 10);
    glVertex2f(25, 3);
    glVertex2f(0, 3);
    glEnd();
}

/// ROAD
void road() {
    glColor3ub(80, 80, 80);
    glBegin(GL_QUADS);
    glVertex2f(0, 4);
    glVertex2f(25, 4);
    glVertex2f(25, 0);
    glVertex2f(0, 0);
    glEnd();
}

/// TREE
void tree() {
    glColor3ub(120, 80, 40);
    glBegin(GL_QUADS);
    glVertex2f(5, 7);
    glVertex2f(5.3, 7);
    glVertex2f(5.3, 9);
    glVertex2f(5, 9);
    glEnd();

    glColor3ub(34, 139, 34);
    glBegin(GL_TRIANGLES);
    glVertex2f(4.3, 9);
    glVertex2f(5.15, 10.5);
    glVertex2f(6, 9);
    glEnd();
}

void building() {

    glColor3ub(100, 149, 237);
    glBegin(GL_QUADS);
    glVertex2f(8, 7);
    glVertex2f(10.5, 7);
    glVertex2f(10.5, 12);
    glVertex2f(8, 12);
    glEnd();

    /// floor lines
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    glVertex2f(8, 8.7);
    glVertex2f(10.5, 8.7);

    glVertex2f(8, 10.4);
    glVertex2f(10.5, 10.4);
    glEnd();

}

/// UPDATE
void update(int value) {
    cloudMove += 0.03f;
    if (cloudMove > 25) cloudMove = -5;

    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

/// DISPLAY
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    sun();
    cloud();
    ground();
    road();
    tree();
    building();

    glFlush();
}

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    gluOrtho2D(0, 25, 0, 15);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("BOgura Scene Updated");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
