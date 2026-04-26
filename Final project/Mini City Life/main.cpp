#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>

float cloudMove = 0.0f;

/// circle
void drawCircle(float cirX, float cirY, float r)
{
    glPushMatrix();
    glTranslatef(cirX, cirY, 0.0f);

    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++) {
        float pi = 3.1416;
        float A = (i * pi) / 180;

        float x = r * cos(A);
        float y = r * sin(A);

        glVertex2f(x, y);
    }

    glEnd();
    glPopMatrix();
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

    glColor3ub(34, 139, 34);

    glBegin(GL_QUADS);
    glVertex2f(0, 10);
    glVertex2f(25, 10);
    glVertex2f(25, 3);
    glVertex2f(0, 3);
    glEnd();
}

void road() {
    /// road base (dark asphalt color)
    glColor3ub(50, 50, 50);
    glBegin(GL_QUADS);
    glVertex2f(0, 4);
    glVertex2f(25, 4);
    glVertex2f(25, 0);
    glVertex2f(0, 0);
    glEnd();

    /// middle white line
    glColor3ub(255, 255, 255);
    glLineWidth(3);

    glBegin(GL_LINES);
    glVertex2f(0, 2);
    glVertex2f(25, 2);
    glEnd();
}

/// TRIANGLE TREE
void treeUsingTriangle() {

    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
    glVertex2f(12, 7);
    glVertex2f(12.3, 7);
    glVertex2f(12.3, 9);
    glVertex2f(12, 9);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);

    glBegin(GL_TRIANGLES);

    // bottom
    glVertex2f(11.5, 9);
    glVertex2f(13, 9);
    glVertex2f(12.25, 10.5);

    // middle
    glVertex2f(11.7, 10);
    glVertex2f(12.8, 10);
    glVertex2f(12.25, 11.5);

    // top
    glVertex2f(11.9, 11);
    glVertex2f(12.6, 11);
    glVertex2f(12.25, 12.5);

    glEnd();
}

/// HOUSE
void house() {

    /// main body (wall)
    glColor3ub(210, 180, 140);
    glBegin(GL_QUADS);
    glVertex2f(15, 7);
    glVertex2f(18, 7);
    glVertex2f(18, 10);
    glVertex2f(15, 10);
    glEnd();

    /// roof
    glColor3ub(139, 69, 19);
    glBegin(GL_TRIANGLES);
    glVertex2f(14.5, 10);
    glVertex2f(18.5, 10);
    glVertex2f(16.75, 12);
    glEnd();

    /// door
    glColor3ub(101, 67, 33);
    glBegin(GL_QUADS);
    glVertex2f(16.2, 7);
    glVertex2f(16.8, 7);
    glVertex2f(16.8, 8.5);
    glVertex2f(16.2, 8.5);
    glEnd();

    /// door
    glColor3ub(255, 215, 0);
    drawCircle(16.7, 7.8, 0.05);

    /// left window
    glColor3ub(173, 216, 230);
    glBegin(GL_QUADS);
    glVertex2f(15.3, 8.5);
    glVertex2f(15.9, 8.5);
    glVertex2f(15.9, 9.3);
    glVertex2f(15.3, 9.3);
    glEnd();

    /// right window
    glBegin(GL_QUADS);
    glVertex2f(17.1, 8.5);
    glVertex2f(17.7, 8.5);
    glVertex2f(17.7, 9.3);
    glVertex2f(17.1, 9.3);
    glEnd();

    /// window border lines
    glColor3ub(0, 0, 0);
    glLineWidth(2);


}

/// BUILDING
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

    building();
    treeUsingTriangle();
    house();

    glFlush();
}

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    gluOrtho2D(0, 25, 0, 15);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Bogura Scene Updated");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}
