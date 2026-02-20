#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

const int boardSize = 8;
const int squareSize = 40;   // 8 * 40 = 320 (fits inside 400)

void init() {
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Gray background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 320.0, 0.0, 320.0);
}

void drawSquare(float x, float y, float size) {
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + size, y);
        glVertex2f(x + size, y + size);
        glVertex2f(x, y + size);
    glEnd();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float startX = 40.0f; // margin from edge
    float startY = 40.0f;

    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {

            // Color logic
            if ((row + col) % 2 == 0)
                glColor3f(1.0f, 1.0f, 1.0f); // white
            else
                glColor3f(0.0f, 0.0f, 0.0f); // black

            float x = startX + col * squareSize;
            float y = startY + row * squareSize;

            drawSquare(x, y, squareSize);
        }
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Stable OpenGL Shapes");

    init();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
