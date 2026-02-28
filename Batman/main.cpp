#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

// Function prototypes
void display();
void lines();
void boxes();

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    // Set window size to match the grid requirements
    glutInitWindowSize(660, 520);
    glutInitWindowPosition(350, 130);
    glutCreateWindow("Batman LOGO");

    // Set the display callback
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

void display() {
    // Clear screen to white
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Set up 2D orthographic projection
    gluOrtho2D(0, 660, 0, 520);

    // Render the logo components
    boxes();
    lines(); // Pink grid drawn on top as a planning/debug reference tool

    glFlush();
}

void boxes() {
    // ---------------------------------------------------------
    // STEP 1: BOTTOM & TOP OUTER BORDERS
    // ---------------------------------------------------------
    for (int y = 40; y <= 460; y += 20) {
        int rowNumber = (y - 40) / 20; // 0-based row index from bottom
        for (int x = 160; x <= 480; x += 20) {

            if (rowNumber == 0 || rowNumber == 1 || rowNumber == 20 || rowNumber == 19) {
                glBegin(GL_QUADS);

                if (rowNumber == 0 || rowNumber == 20) {
                    glColor3f(0, 0, 0);          // Black — outermost borders
                }
                else {
                    glColor3f(0.969, 0.91, 0);   // Yellow — inner borders
                }

                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 20);
                glVertex2f(x, y + 20);
                glEnd();
            }
        }
    }

    // ---------------------------------------------------------
    // STEP 2: LEFT & RIGHT SIDE BORDERS
    // ---------------------------------------------------------
    for (int x = 20; x <= 620; x += 20) {
        int colNumber = (x - 20) / 20; // 0-based column index from left
        for (int y = 180; y <= 300; y += 20) {

            if (colNumber == 0 || colNumber == 1 || colNumber == 29 || colNumber == 30) {
                glBegin(GL_QUADS);

                if (colNumber == 0 || colNumber == 30) {
                    glColor3f(0, 0, 0);          // Black — outermost borders
                }
                else {
                    glColor3f(0.969, 0.91, 0);   // Yellow — inner borders
                }

                glVertex2f(x, y);
                glVertex2f(x + 20, y);
                glVertex2f(x + 20, y + 20);
                glVertex2f(x, y + 20);
                glEnd();
            }
        }
    }

    // ---------------------------------------------------------
    // STEP 4: CENTRAL HORIZONTAL BLACK BAR
    // ---------------------------------------------------------
    for (int y = 200; y <= 280; y += 20) {
        for (int x = 60; x <= 580; x += 20) {
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0); // Black — solid central bar
            glVertex2f(x, y);
            glVertex2f(x + 20, y);
            glVertex2f(x + 20, y + 20);
            glVertex2f(x, y + 20);
            glEnd();
        }
    }

    // ---------------------------------------------------------
    // STEP 5: WING STAIRCASE (UPPER)
    // ---------------------------------------------------------
    for (int row = 0; row < 6; row++) {
        int y = 320 + row * 20;

        // Left side
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0); // Black
        glVertex2f(40 + row * 20, y);
        glVertex2f(60 + row * 20, y);
        glVertex2f(60 + row * 20, y + 20);
        glVertex2f(40 + row * 20, y + 20);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0); // Yellow
        glVertex2f(60 + row * 20, y);
        glVertex2f(80 + row * 20, y);
        glVertex2f(80 + row * 20, y + 20);
        glVertex2f(60 + row * 20, y + 20);
        glEnd();

        // Right side (mirror)
        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0); // Yellow
        glVertex2f(580 - row * 20, y);
        glVertex2f(600 - row * 20, y);
        glVertex2f(600 - row * 20, y + 20);
        glVertex2f(580 - row * 20, y + 20);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0, 0, 0); // Black
        glVertex2f(600 - row * 20, y);
        glVertex2f(620 - row * 20, y);
        glVertex2f(620 - row * 20, y + 20);
        glVertex2f(600 - row * 20, y + 20);
        glEnd();
    }

    // ---------------------------------------------------------
    // STEP 6: WING STAIRCASE (LOWER)
    // ---------------------------------------------------------
    for (int row = 0; row < 6; row++) {
        int y = 60 + row * 20;

        // Bottom-Left
        glBegin(GL_QUADS);
        glColor3f(0, 0, 0); // Black
        glVertex2f(140 - row * 20, y);
        glVertex2f(160 - row * 20, y);
        glVertex2f(160 - row * 20, y + 20);
        glVertex2f(140 - row * 20, y + 20);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0); // Yellow
        glVertex2f(160 - row * 20, y);
        glVertex2f(180 - row * 20, y);
        glVertex2f(180 - row * 20, y + 20);
        glVertex2f(160 - row * 20, y + 20);
        glEnd();

        // Bottom-Right (mirror)
        glBegin(GL_QUADS);
        glColor3f(0.969, 0.91, 0); // Yellow
        glVertex2f(480 + row * 20, y);
        glVertex2f(500 + row * 20, y);
        glVertex2f(500 + row * 20, y + 20);
        glVertex2f(480 + row * 20, y + 20);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0, 0, 0); // Black
        glVertex2f(500 + row * 20, y);
        glVertex2f(520 + row * 20, y);
        glVertex2f(520 + row * 20, y + 20);
        glVertex2f(500 + row * 20, y + 20);
        glEnd();
    }

    // ---------------------------------------------------------
    // STEP 7: WING DIP MARKERS
    // ---------------------------------------------------------
    for (int x = 160; x <= 480; x += 20) {
        int colNumber = (x - 160) / 20;
        int y = 400;
        glBegin(GL_QUADS);
        if (colNumber != 6 && colNumber != 10) {
            glColor3f(0.969, 0.91, 0); // Yellow
        }
        else {
            glColor3f(0, 0, 0); // Black — wing dip markers
        }
        glVertex2f(x, y);
        glVertex2f(x + 20, y);
        glVertex2f(x + 20, y + 20);
        glVertex2f(x, y + 20);
        glEnd();
    }
}

void lines() {
    // PLANNING/DEBUG TOOL — Pink grid overlay
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.969, 0.0f, 0.373); // Pink

    // Horizontal grid lines
    for (int y = 0; y <= 520; y += 20) {
        glVertex2f(0, y);
        glVertex2f(660, y);
    }

    // Vertical grid lines
    for (int x = 0; x <= 660; x += 20) {
        glVertex2f(x, 0);
        glVertex2f(x, 520);
    }
    glEnd();
}
