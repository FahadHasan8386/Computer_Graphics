#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

void lines();
void boxes();

void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    gluOrtho2D(0, 660, 0, 520);

    boxes();
    lines(); // pink grid drawn on top as a planning/debug reference tool

    glFlush();
}

void boxes() {

    for (int y = 40; y <= 460; y += 20) {
        int rowNumber = (y - 40) / 20;
        for (int x = 160; x <= 480; x += 20) {

            if (rowNumber == 0 || rowNumber == 1 || rowNumber == 20 || rowNumber == 19) {
                glBegin(GL_QUADS);

                if (rowNumber == 0) {
                    glColor3f(0, 0, 0);
                }
                else if (rowNumber == 1) {
                    glColor3f(0.969, 0.91, 0);
                }
                else if (rowNumber == 19) {
                    glColor3f(0.969, 0.91, 0); // Yellow — inner top border
                }
                else if (rowNumber == 20) {
                    glColor3f(0, 0, 0);
                }

                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 20);
                glVertex2f(x, y + 20);
                glEnd();
            }
        }
    }

    for (int x = 20; x <= 620; x += 20) {
        int colNumber = (x - 20) / 20;
        for (int y = 180; y <= 300; y += 20) {

            if (colNumber == 0 || colNumber == 1 || colNumber == 29 || colNumber == 30) {
                glBegin(GL_QUADS);

                if (colNumber == 0) {
                    glColor3f(0, 0, 0);        /// Black left border
                }
                else if (colNumber == 1) {
                    glColor3f(0.969, 0.91, 0); /// Yellow left border
                }
                else if (colNumber == 29) {
                    glColor3f(0.969, 0.91, 0); /// Yellow  right border
                }
                else if (colNumber == 30) {
                    glColor3f(0, 0, 0);        /// Black right border
                }

                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 20);
                glVertex2f(x, y + 20);
                glEnd();
            }
        }
    }



    for (int y = 200; y <= 280; y += 20) {
        int rowNumber = (y - 200) / 20;
        for (int x = 60; x <= 580; x += 20) {

            if (rowNumber >= 0 && rowNumber <= 4) {
                glBegin(GL_QUADS);
                glColor3f(0, 0, 0);
                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 20);
                glVertex2f(x, y + 20);
                glEnd();
            }
        }
    }


    for (int row = 0; row < 6; row++) {
        int y = 320 + row * 20;


        glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(40 + row * 20, y);
        glVertex2f(60 + row * 20, y);
        glVertex2f(60 + row * 20, y + 20);
        glVertex2f(40 + row * 20, y + 20);
        glEnd();


        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0);
        glVertex2f(60 + row * 20, y);
        glVertex2f(80 + row * 20, y);
        glVertex2f(80 + row * 20, y + 20);
        glVertex2f(60 + row * 20, y + 20);
        glEnd();


        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0);
        glVertex2f(580 - row * 20, y);
        glVertex2f(600 - row * 20, y);
        glVertex2f(600 - row * 20, y + 20);
        glVertex2f(580 - row * 20, y + 20);
        glEnd();


        glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(600 - row * 20, y);
        glVertex2f(620 - row * 20, y);
        glVertex2f(620 - row * 20, y + 20);
        glVertex2f(600 - row * 20, y + 20);
        glEnd();
    }

    for (int row = 0; row < 6; row++) {
        int y = 60 + row * 20;


        glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(140 - row * 20, y);
        glVertex2f(160 - row * 20, y);
        glVertex2f(160 - row * 20, y + 20);
        glVertex2f(140 - row * 20, y + 20);
        glEnd();


        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0);
        glVertex2f(160 - row * 20, y);
        glVertex2f(180 - row * 20, y);
        glVertex2f(180 - row * 20, y + 20);
        glVertex2f(160 - row * 20, y + 20);
        glEnd();


        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0);
        glVertex2f(480 + row * 20, y);
        glVertex2f(500 + row * 20, y);
        glVertex2f(500 + row * 20, y + 20);
        glVertex2f(480 + row * 20, y + 20);
        glEnd();


        glBegin(GL_QUADS);
        glColor3f(0, 0, 0);
        glVertex2f(500 + row * 20, y);
        glVertex2f(520 + row * 20, y);
        glVertex2f(520 + row * 20, y + 20);
        glVertex2f(500 + row * 20, y + 20);
        glEnd();
    }

    for (int x = 160; x <= 480; x += 20) {
        int colNumber = (x - 160) / 20;
        int y = 400;
        if (colNumber != 6 && colNumber != 10) {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black — wing
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    for (int x = 60; x <= 580; x += 20) {
        int colNumber = (x - 60) / 20;
        int y = 180;
        if ((colNumber >= 1 && colNumber <= 25)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black — nearly full width
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow — just the border edges
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }

    for (int x = 80; x <= 560; x += 20) {
        int colNumber = (x - 80) / 20;
        int y = 160;
        if ((colNumber >= 1 && colNumber <= 23)) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }



    for (int x = 160; x <= 480; x += 20) {
        int colNumber = (x - 160) / 20;
        int y = 80;
        if (colNumber == 2 || colNumber == 8 || colNumber == 14) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0);
        }
        else {
            glBegin(GL_QUADS);
            glColor3f(0.969, 0.91, 0);
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }
}


void lines() {

    for (int y = 0; y < 520; y += 20) {
        glBegin(GL_LINES);
        glColor3f(0.969, 0, 0.373); // Pink
        glVertex2f(0, y);
        glVertex2f(660, y);
        glEnd();
    }

    for (int x = 20; x < 660; x += 20) {
        glBegin(GL_LINES);
        glColor3f(0.969, 0, 0.373);
        glVertex2f(x, 0);
        glVertex2f(x, 660);
        glEnd();
    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(660, 520);
    glutInitWindowPosition(350, 130);
    glutCreateWindow("Task Batman LOGO");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
