#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

const int boardSize = 8;
const int squareSize = 50;

void init() {
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f);  s
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0 , 400 , 0 , 400);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    float x, y = 0;

    for(int row = 0; row < boardSize; row++) {

        x = 0;

        for(int col = 0; col < boardSize; col++) {


            if((row + col) % 2 == 0)
                glColor3f(1,1,1);
            else
                glColor3f(0,0,0);

            glBegin(GL_QUADS);
                glVertex2f(x, y);
                glVertex2f(x + squareSize, y);
                glVertex2f(x + squareSize, y + squareSize);
                glVertex2f(x, y + squareSize);
            glEnd();

            x += squareSize;
        }

        y += squareSize;
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Chessboard");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
