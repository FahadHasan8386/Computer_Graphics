#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

// for Animation
float cloudMove = -250.0f;
float boatMove = 250.0f;
float t = 1.0f;
bool dayIncreasing = false;
bool startAnimation = false;

// for circle
void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/180;
        glVertex2f(cx+r*cos(A),cy+r*sin(A));
    }
    glEnd();
}

// for window
void drawWindow(float x,float y)
{
    glColor3f(1.0,1.0,0.8);
    glBegin(GL_QUADS);
    glVertex2f(x,y);
    glVertex2f(x+15,y);
    glVertex2f(x+15,y+20);
    glVertex2f(x,y+20);
    glEnd();
}

// cloud
void drawCloud(float x,float y)
{
    drawCircle(x,y,18);
    drawCircle(x+20,y+10,20);
    drawCircle(x+40,y,18);
}

// tree
void drawTree(float x)
{
    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(x, -80);
    glVertex2f(x+10, -80);
    glVertex2f(x+10, -40);
    glVertex2f(x, -40);
    glEnd();

    glColor3f(0.1, 0.6, 0.2);
    drawCircle(x+5, -25, 15);
    drawCircle(x-5, -35, 12);
    drawCircle(x+15, -35, 12);
}



// for boat
void drawBoat()
{
    glPushMatrix();
    glTranslatef(boatMove,0,0);

    glColor3f(0.1,0.2,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-50,-180);
    glVertex2f(50,-180);
    glVertex2f(30,-150);
    glVertex2f(-30,-150);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(0,-150);
    glVertex2f(0,-100);
    glVertex2f(30,-150);
    glEnd();

    glPopMatrix();
}

// building
void drawBuilding(float x,float width,float height,float r,float g,float b)
{
    glColor3f(r,g,b);

    glBegin(GL_QUADS);
    glVertex2f(x,-50);
    glVertex2f(x+width,-50);
    glVertex2f(x+width,height);
    glVertex2f(x,height);
    glEnd();

    for(float i=x+10;i<x+width-20;i+=25)
    {
        for(float j=-30;j<height-20;j+=35)
        {
            drawWindow(i,j);
        }
    }
}

// road
void drawRoad()
{
// MAIN ROAD (Top Road)
glColor3f(0.1, 0.1, 0.1); // dark road
glBegin(GL_QUADS);
glVertex2f(-250, -30);
glVertex2f(250, -30);
glVertex2f(250, -80);
glVertex2f(-250, -80);
glEnd();




    }


// scence-
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    gluOrtho2D(-250,250,-250,250);

    // SKY
    float r = 0.05 + t * 0.6;
    float g = 0.05 + t * 0.8;
    float b = 0.2  + t * 0.8;

    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(-250,250);
    glVertex2f(250,250);
    glVertex2f(250,-50);
    glVertex2f(-250,-50);
    glEnd();

    // SUN/MOON
    float sr = 1.0;
    float sg = 0.9 * t + 1.0 * (1 - t);
    float sb = 0.0 * t + 1.0 * (1 - t);

    glColor3f(sr, sg, sb);
    drawCircle(180,180,25);

    // CLOUD
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(cloudMove,0,0);
    drawCloud(-150,180);
    drawCloud(20,200);
    drawCloud(120,170);
    glPopMatrix();

    // BUILDINGS
    drawBuilding(-230,50,120,0.8,0.2,0.2);
    drawBuilding(-170,50,150,0.2,0.4,0.8);
    drawBuilding(-110,50,100,0.9,0.7,0.2);
    drawBuilding(-50,50,170,0.5,0.3,0.8);
    drawBuilding(10,50,130,0.3,0.7,0.4);
    drawBuilding(70,50,160,0.9,0.5,0.3);
    drawBuilding(130,50,110,0.2,0.8,0.8);
    drawBuilding(190,50,145,0.8,0.3,0.6);

    // TREES
    drawTree(-200);
    drawTree(-140);
    drawTree(-80);
    drawTree(40);
    drawTree(100);
    drawTree(160);

    // ROAD
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
    glVertex2f(-250,-80);
    glVertex2f(250,-80);
    glVertex2f(250,-100);
    glVertex2f(-250,-100);
    glEnd();

    // road
    drawRoad();



    // RIVER
    glColor3f(0.4,0.8,1.0);
    glBegin(GL_QUADS);
    glVertex2f(-250,-70);
    glVertex2f(250,-70);
    glVertex2f(250,-250);
    glVertex2f(-250,-250);
    glEnd();

    // WATER LINES
    glColor3f(1,1,1);
    for(int i=-240;i<250;i+=50)
    {
        glBegin(GL_LINES);
        glVertex2f(i,-130);
        glVertex2f(i+25,-130);

        glVertex2f(i,-180);
        glVertex2f(i+25,-180);

        glVertex2f(i,-220);
        glVertex2f(i+25,-220);
        glEnd();
    }

    // BOAT
    drawBoat();

    glutSwapBuffers();
}

// ---------------- UPDATE ----------------
void update(int value)
{
    if(startAnimation)
    {
        cloudMove += 2.0f;
        if(cloudMove > 300) cloudMove = -300;

        boatMove -= 5.0f;
        if(boatMove < -300) boatMove = 300;


        if(dayIncreasing)
            t += 0.002f;
        else
            t -= 0.002f;

        if(t >= 1.0f) dayIncreasing = false;
        if(t <= 0.0f) dayIncreasing = true;
    }

    glutPostRedisplay();
    glutTimerFunc(25,update,0);
}

// ---------------- KEYBOARD ----------------
void keyboard(unsigned char key,int x,int y)
{
    if(key=='s' || key=='S')
        startAnimation=true;
}


// Main
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1000,700);
    glutCreateWindow("City Animation");

    glClearColor(0,0,0,1);

    glutDisplayFunc(drawScene);
    glutTimerFunc(25, update, 0);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
