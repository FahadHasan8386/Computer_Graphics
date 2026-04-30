#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1416

bool isNight = false;

// Draw circle for tree leafs
void drawCircle(float cx, float cy, float r, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= segments; ++i) {
        float angle = 2.0f * PI * i / segments;
        float x = r * cosf(angle);
        float y = r * sinf(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}


void drawRoads() {

    //vertical road
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(60, 0);
    glVertex2f(60, 20);
    glVertex2f(40, 20);
    glVertex2f(40, 0);
    glEnd();

    //horizontal road
    glBegin(GL_QUADS);
    glVertex2f(0, 20);
    glVertex2f(100, 20);
    glVertex2f(100, 45);
    glVertex2f(0, 45);
    glEnd();

    //road Horizontal divider
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0, 32);
    glVertex2f(100, 32);
    glVertex2f(100, 34);
    glVertex2f(0, 34);
    glEnd();

    //road verticla divider
    glBegin(GL_QUADS);
    glVertex2f(49, 0);
    glVertex2f(51, 0);
    glVertex2f(51, 20);
    glVertex2f(49, 20);
    glEnd();

    //upeer road sign
    for (int x = 10; x <= 100; x += 20) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(x, 38);//10,38
        glVertex2f(x+10, 38);//20,38
        glVertex2f(x+10, 40);//20,40
        glVertex2f(x, 40);//10,40
        glEnd();

    }

    //lower road sign
    for (int x = 0; x <= 100; x += 20) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(x, 26);//0,26
        glVertex2f(x + 10, 26);//10,28
        glVertex2f(x + 10, 28);//10,28
        glVertex2f(x, 28);//0,28
        glEnd();

    }

}

void roadBorder() {

    //left side Horizontal border for SM
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0, 20);
    glVertex2f(40, 20);
    glVertex2f(40, 22);
    glVertex2f(0, 22);
    glEnd();

    for (int x = 0; x < 40; x += 4) {

        glColor3f(0.647f, 0.165f, 0.165f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, 20);
        glVertex2f(x+4, 20);
        glVertex2f(x+4, 22);
        glVertex2f(x, 22);
        glEnd();
    }

    //Right side Horizontal border for forest
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(60, 20);
    glVertex2f(100, 20);
    glVertex2f(100, 22);
    glVertex2f(60, 22);
    glEnd();

    for (int x = 60; x < 100; x += 4) {

        glColor3f(0.647f, 0.165f, 0.165f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, 20);
        glVertex2f(x + 4, 20);
        glVertex2f(x + 4, 22);
        glVertex2f(x, 22);
        glEnd();
    }

    //left side Birtical border for SM
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(38, 0);
    glVertex2f(40, 0);
    glVertex2f(40, 20);
    glVertex2f(38, 20);
    glEnd();

    for (int y = 0; y < 20; y += 4) {

        glColor3f(0.647f, 0.165f, 0.165f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(38, y);//38,0
        glVertex2f(40, y);//40,0
        glVertex2f(40, y+4);//40,4
        glVertex2f(38, y+4);//38,4
        glEnd();
    }

    //Righ side Birtical border for Forest
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(60, 0);
    glVertex2f(62, 0);
    glVertex2f(62, 20);
    glVertex2f(60, 20);
    glEnd();

    for (int y = 0; y < 20; y += 4) {

        glColor3f(0.647f, 0.165f, 0.165f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(60, y);//60,0
        glVertex2f(62, y);//62,0
        glVertex2f(62, y + 4);//62,4
        glVertex2f(60, y + 4);//60,4
        glEnd();
    }

}


void drawSky(double r, double g, double b) {

    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(0, 50);
    glVertex2f(100, 50);
    glVertex2f(100, 80);
    glVertex2f(0, 80);
    glEnd();
}


//------All sky element-------------
void drawStars() {
    glColor3f(1.0f, 1.0f, 1.0f); // White stars
    srand(42);

    for (int i = 0; i < 100; i++) {
        float x = rand() % 100;
        float y = 60 + rand() % 40;
        drawCircle(x, y, 0.2, 100);
    }
}

void drawSun(float x, float y, float radius) {
    // Main sun body
    glColor3f(1.0f, 0.843f, 0.0f);
    drawCircle(x, y, radius, 100);

    // Sun glow effect
    glColor4f(1.0f, 0.843f, 0.0f, 0.3f);
    drawCircle(x, y, radius * 1.5f, 100);
}

void drawCrescentMoon(float x, float y, float radius) {
    // Full moon base (bright)
    glColor3f(1.0f, 1.0f, 0.8f);  // pale yellow
    drawCircle(x, y, radius, 100);

    // Overlapping circle to form crescent
    glColor3f(0.05f, 0.05f, 0.2f); // night sky color (to "cut" moon)
    drawCircle(x + radius * 0.2f, y + radius * 0.1f, radius * 0.85f, 100);
}

//clouds global variable
double cloudX1 = 10;
double cloudX2 = 80;
double cloudX3 = 50;

void drawCloud(float x, float y, float scale, float r, float g, float b) {
    glColor3f(r, g, b); // Set cloud color

    drawCircle(x, y, 4.0f * scale, 100);
    drawCircle(x + 3.0f * scale, y + 1.0f * scale, 4.5f * scale, 100);
    drawCircle(x + 6.0f * scale, y, 4.0f * scale, 100);
    drawCircle(x + 3.0f * scale, y - 1.5f * scale, 4.0f * scale, 100);
}

void updateClouds(int value) {
    cloudX1 += 0.2;
    cloudX2 -= 0.4;
    cloudX3 += 0.3;

    // Reset positions further left so clouds enter smoothly
    if (cloudX1 > 110.0f) cloudX1 = -30.0f;
    if (cloudX2 < -20.0f) cloudX2 = +120.0f;
    if (cloudX3 > 110.0f) cloudX3 = -35.0f;

    glutPostRedisplay();
    glutTimerFunc(30, updateClouds, 0);
}

//Plans global variable
float planeX = -20.0f;
float planeSpeed = 0.2f;

float planeX2 = 120.0f;
float planeSpeed2 = 0.4f;

void drawPlane() {
    glPushMatrix();
    glTranslatef(planeX, 73.0f, 0.0f); // Bottom Y = 73
    glScalef(0.4, 0.4, 0);

    // --- MAIN BODY  ---

    // Fuselage - White
    glColor3f(1.0f, 1.0f, 1.0f); // Pure white
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(10.0f, 2.0f);
    glVertex2f(0.0f, 2.0f);
    glEnd();

    // Blue cheat line
    glColor3f(0.0f, 0.4f, 0.8f); // Airbus blue
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 1.8f);
    glVertex2f(10.0f, 1.8f);
    glVertex2f(10.0f, 2.0f);
    glVertex2f(0.0f, 2.0f);
    glEnd();

    // Tail - Blue with red tip
    glColor3f(0.0f, 0.4f, 0.8f); // Airbus blue
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 2.0f);
    glVertex2f(2.0f, 2.0f);
    glVertex2f(1.0f, 4.0f);
    glVertex2f(0.0f, 4.0f);
    glEnd();

    // Tail tip - Red
    glColor3f(0.9f, 0.1f, 0.1f); // Red tip
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 3.5f);
    glVertex2f(0.5f, 3.5f);
    glVertex2f(0.25f, 4.0f);
    glEnd();

    // Tail logo area
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5f, 2.5f);
    glVertex2f(1.0f, 2.5f);
    glVertex2f(0.75f, 3.0f);
    glEnd();

    // Nose - Gray with blue tip
    glColor3f(0.7f, 0.7f, 0.7f); // Gray nose
    glBegin(GL_TRIANGLES);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(12.0f, 1.0f);
    glVertex2f(10.0f, 2.0f);
    glEnd();

    // Nose tip - Blue
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_TRIANGLES);
    glVertex2f(11.0f, 0.8f);
    glVertex2f(11.5f, 1.0f);
    glVertex2f(11.0f, 1.2f);
    glEnd();

    // Cockpit windows - Black
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(9.2f, 1.0f);
    glVertex2f(9.8f, 1.0f);
    glVertex2f(9.8f, 1.6f);
    glVertex2f(9.2f, 1.6f);
    glEnd();

    // Engine nacelles (under wings)
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray engines
    // Left engine
    glBegin(GL_POLYGON);
    glVertex2f(4.5f, -0.5f);
    glVertex2f(6.5f, -0.5f);
    glVertex2f(6.5f, 0.0f);
    glVertex2f(4.5f, 0.0f);
    glEnd();

    // Right engine
    glBegin(GL_POLYGON);
    glVertex2f(4.5f, 2.0f);
    glVertex2f(6.5f, 2.0f);
    glVertex2f(6.5f, 2.5f);
    glVertex2f(4.5f, 2.5f);
    glEnd();

    // Engine details - Silver rings
    glColor3f(0.8f, 0.8f, 0.9f); // Silver
    // Bottom engine ring
    glBegin(GL_POLYGON);
    glVertex2f(4.7f, -0.5f);
    glVertex2f(6.3f, -0.5f);
    glVertex2f(6.3f, -0.4f);
    glVertex2f(4.7f, -0.4f);
    glEnd();

    // Top engine ring
    glBegin(GL_POLYGON);
    glVertex2f(4.7f, 2.5f);
    glVertex2f(6.3f, 2.5f);
    glVertex2f(6.3f, 2.4f);
    glVertex2f(4.7f, 2.4f);
    glEnd();

    // Bottom Wing - Blue with white stripe
    glColor3f(0.0f, 0.4f, 0.8f); // Airbus blue
    glBegin(GL_QUADS);
    glVertex2f(5.0f, 0.0f);
    glVertex2f(4.0f, -3.0f);
    glVertex2f(5.0f, -3.0f);
    glVertex2f(7.0f, 0.0f);
    glEnd();

    // Bottom wing stripe - White
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(5.2f, -1.0f);
    glVertex2f(4.8f, -2.0f);
    glVertex2f(5.2f, -2.0f);
    glVertex2f(5.8f, -1.0f);
    glEnd();

    // Top Wing - Blue with white stripe
    glColor3f(0.0f, 0.4f, 0.8f); // Airbus blue
    glBegin(GL_QUADS);
    glVertex2f(5.0f, 2.0f);
    glVertex2f(3.0f, 4.0f);
    glVertex2f(4.0f, 4.0f);
    glVertex2f(6.0f, 2.0f);
    glEnd();

    // Top wing stripe - White
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(4.8f, 3.0f);
    glVertex2f(3.8f, 3.8f);
    glVertex2f(4.2f, 3.8f);
    glVertex2f(5.2f, 3.0f);
    glEnd();

    // Winglets (wing tips) - Blue
    // Bottom winglet
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_TRIANGLES);
    glVertex2f(4.0f, -3.0f);
    glVertex2f(3.5f, -3.5f);
    glVertex2f(4.0f, -3.5f);
    glEnd();

    // Top winglet
    glBegin(GL_TRIANGLES);
    glVertex2f(3.0f, 4.0f);
    glVertex2f(2.5f, 4.5f);
    glVertex2f(3.0f, 4.5f);
    glEnd();

    // Windows
    glColor3f(0.2f, 0.5f, 0.8f);

    // Window frames
    glColor3f(0.1f, 0.1f, 0.1f); // Black frames
    float windowSpacing = 1.5f;

    for (int i = 0; i < 6; i++) {
        float xPos = 2.0f + i * windowSpacing;
        if (xPos < 8.5f) {
            glBegin(GL_LINE_LOOP);
            glVertex2f(xPos, 0.5f);
            glVertex2f(xPos + 0.8f, 0.5f);
            glVertex2f(xPos + 0.8f, 1.5f);
            glVertex2f(xPos, 1.5f);
            glEnd();

            // Window glass
            glColor3f(0.2f, 0.5f, 0.8f);
            glBegin(GL_POLYGON);
            glVertex2f(xPos + 0.1f, 0.6f);
            glVertex2f(xPos + 0.7f, 0.6f);
            glVertex2f(xPos + 0.7f, 1.4f);
            glVertex2f(xPos + 0.1f, 1.4f);
            glEnd();

            glColor3f(0.1f, 0.1f, 0.1f); // Reset to black for frames
        }
    }

    // Landing gear (simplified)
    glColor3f(0.4f, 0.4f, 0.4f); // Gray gear
    // Front gear
    glBegin(GL_POLYGON);
    glVertex2f(8.5f, -0.3f);
    glVertex2f(9.0f, -0.3f);
    glVertex2f(9.0f, 0.0f);
    glVertex2f(8.5f, 0.0f);
    glEnd();

    // Main gear (under wings)
    glBegin(GL_POLYGON);
    glVertex2f(4.5f, -0.3f);
    glVertex2f(5.5f, -0.3f);
    glVertex2f(5.5f, 0.0f);
    glVertex2f(4.5f, 0.0f);
    glEnd();

    // Logo/registration on fuselage
    glColor3f(0.0f, 0.4f, 0.8f); // Airbus blue
    glBegin(GL_POLYGON);
    glVertex2f(3.0f, 1.9f);
    glVertex2f(4.0f, 1.9f);
    glVertex2f(4.0f, 1.95f);
    glVertex2f(3.0f, 1.95f);
    glEnd();

    glPopMatrix();
}

// Second plane moving opposite direction
void drawPlane2(float y_pos) {
    glPushMatrix();
    glTranslatef(planeX2, y_pos, 0.0f);
    glScalef(-0.4, 0.4, 0); // Scaled and flipped horizontally

    // --- MAIN BODY  ---
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(10.0f, 2.0f);
    glVertex2f(0.0f, 2.0f);
    glEnd();

    // Blue cheat line
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 1.8f);
    glVertex2f(10.0f, 1.8f);
    glVertex2f(10.0f, 2.0f);
    glVertex2f(0.0f, 2.0f);
    glEnd();

    // Tail
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 2.0f);
    glVertex2f(2.0f, 2.0f);
    glVertex2f(1.0f, 4.0f);
    glVertex2f(0.0f, 4.0f);
    glEnd();

    // Tail tip
    glColor3f(0.9f, 0.1f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 3.5f);
    glVertex2f(0.5f, 3.5f);
    glVertex2f(0.25f, 4.0f);
    glEnd();

    // Nose
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_TRIANGLES);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(12.0f, 1.0f);
    glVertex2f(10.0f, 2.0f);
    glEnd();

    // Cockpit
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(9.2f, 1.0f);
    glVertex2f(9.8f, 1.0f);
    glVertex2f(9.8f, 1.6f);
    glVertex2f(9.2f, 1.6f);
    glEnd();

    // Wings
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(5.0f, 0.0f);
    glVertex2f(4.0f, -3.0f);
    glVertex2f(5.0f, -3.0f);
    glVertex2f(7.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(5.0f, 2.0f);
    glVertex2f(3.0f, 4.0f);
    glVertex2f(4.0f, 4.0f);
    glVertex2f(6.0f, 2.0f);
    glEnd();

    // Windows
    glColor3f(0.2f, 0.5f, 0.8f);
    for (int i = 0; i < 6; i++) {
        float xPos = 2.0f + i * 1.5f;
        if (xPos < 8.5f) {
            glBegin(GL_POLYGON);
            glVertex2f(xPos + 0.1f, 0.6f);
            glVertex2f(xPos + 0.7f, 0.6f);
            glVertex2f(xPos + 0.7f, 1.4f);
            glVertex2f(xPos + 0.1f, 1.4f);
            glEnd();
        }
    }

    glPopMatrix();
}

void updatePlane(int value) {
    planeX += planeSpeed;
    if (planeX > 120.0f) planeX = -30.0f;

    planeX2 -= planeSpeed2;
    if (planeX2 < -20.0f) planeX2 = 120.0f;

    glutPostRedisplay();
    glutTimerFunc(30, updatePlane, 0);
}

//----all road elements----

//cars and bus global variable
float carX1 = -30.0f;
float carSpeed1 = 0.5f;

float carX2 = 120.0f;
float carSpeed2 = -0.4f;

float carX3 = -40.0f;
float carSpeed3 = 0.6f;

float carX4 = 150.0f;
float carSpeed4 = -0.5f;

bool nightLight = false;

void drawRedCar() {
    glPushMatrix();
    glTranslatef(carX1, 26.0f, 0.0f);
    glScalef(1.5f, 1.5f, 1.0f);

    //WHEELS
    drawCircle(-1.8f, -1.7f, 0.8f, 100);
    drawCircle(-3.8f, -1.7f, 0.8f, 100);
    drawCircle(-8.5f, -1.7f, 0.8f, 100);

    // HEADLIGHT (NIGHT ONLY)
    if (nightLight) {
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 200);
        glVertex3f(4.5f, 0.5f, 0.0f);
        glVertex3f(4.5f, -2.5f, 0.0f);
        glVertex3f(-0.5f, -1.3f, 0.0f);
        glVertex3f(-0.5f, -1.0f, 0.0f);
        glEnd();
    }

    // --- CAR BODY (RED PARTS) ---
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-9.2f, -1.95f, 0.0f);
    glVertex3f(-0.5f, -1.95f, 0.0f);
    glVertex3f(-0.5f, -0.8f, 0.0f);
    glVertex3f(-9.2f, -0.8f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-3.1f, 0.5f, 0.0f);
    glVertex3f(-9.2f, 0.5f, 0.0f);
    glVertex3f(-9.2f, 1.69f, 0.0f);
    glVertex3f(-3.1f, 1.69f, 0.0f);
    glEnd();

    // Pillars
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-6.05f, 0.5f, 0.0f);
    glVertex3f(-6.05f, -0.85f, 0.0f);
    glVertex3f(-6.0f, -0.85f, 0.0f);
    glVertex3f(-6.0f, 0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-3.1f, 0.5f, 0.0f);
    glVertex3f(-3.15f, 0.5f, 0.0f);
    glVertex3f(-3.15f, -1.95f, 0.0f);
    glVertex3f(-3.1f, -1.95f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-9.2f, 0.5f, 0.0f);
    glVertex3f(-9.15f, 0.5f, 0.0f);
    glVertex3f(-9.15f, -1.95f, 0.0f);
    glVertex3f(-9.2f, -1.95f, 0.0f);
    glEnd();

    // Windows
    glBegin(GL_TRIANGLES);
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex3f(-3.1f, 0.9f, 0.0f);
    glVertex3f(-3.1f, -0.85f, 0.0f);
    glVertex3f(-0.5f, -0.85f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex3f(-6.0f, 0.5f, 0.0f);
    glVertex3f(-3.15f, 0.5f, 0.0f);
    glVertex3f(-3.15f, -0.85f, 0.0f);
    glVertex3f(-6.0f, -0.85f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex3f(-6.05f, 0.5f, 0.0f);
    glVertex3f(-9.15f, 0.5f, 0.0f);
    glVertex3f(-9.15f, -0.85f, 0.0f);
    glVertex3f(-6.05f, -0.85f, 0.0f);
    glEnd();

    glPopMatrix();
}

void drawMiniCar() {
    glPushMatrix();
    glTranslatef(carX4, 40.0f, 0.0f);
    glScalef(-7.5f, 7.5f, 1.0f);

    float wheelY = -0.52f;
    float wheelRadius = 0.1f;
    drawCircle(0.1f, wheelY, wheelRadius, 100);
    drawCircle(-0.4f, wheelY, wheelRadius, 100);

    if (nightLight) {
        glBegin(GL_POLYGON);
        glColor3ub(192, 192, 192);
        glVertex2f(0.3f, -0.45f);
        glVertex2f(0.8f, -0.6f);
        glVertex2f(0.8f, -0.1f);
        glVertex2f(0.3f, -0.3f);
        glEnd();
    }

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.3f, -0.5f);
    glVertex2f(-0.6f, -0.5f);
    glVertex2f(-0.6f, -0.2f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.02f);
    glVertex2f(-0.35f, 0.02f);
    glVertex2f(-0.35f, -0.2f);
    glVertex2f(0.0f, -0.2f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.15f, -0.2f);
    glVertex2f(0.0f, 0.02f);
    glVertex2f(-0.35f, 0.02f);
    glVertex2f(-0.45f, -0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.8f, 1.0f);
    glVertex2f(0.15f, -0.2f);
    glVertex2f(0.0f, 0.02f);
    glVertex2f(-0.35f, 0.02f);
    glVertex2f(-0.45f, -0.2f);
    glEnd();

    glPopMatrix();
}

void drawBlueBus() {
    glPushMatrix();
    glTranslatef(carX3, 33.0f, 0.0f);
    glScalef(1.5f, 1.5f, 1.0f);

    float wheelY = -2.0f;
    float wheelRadius = 0.8f;

    drawCircle(2.0f, wheelY, wheelRadius, 100);
    drawCircle(5.0f, wheelY, wheelRadius, 100);
    drawCircle(7.0f, wheelY, wheelRadius, 100);
    drawCircle(10.0f, wheelY, wheelRadius, 100);

    glColor3f(0.0f, 0.0f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, -2.0f, 0.0f);
    glVertex3f(12.0f, -2.0f, 0.0f);
    glVertex3f(12.0f, 0.5f, 0.0f);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(12.0f, 0.5f, 0.0f);
    glVertex3f(12.0f, 3.0f, 0.0f);
    glVertex3f(0.0f, 3.0f, 0.0f);
    glEnd();

    if (nightLight) {
        glBegin(GL_POLYGON);
        glColor3ub(255, 255, 200);
        glVertex3f(12.5f, -0.5f, 0.0f);
        glVertex3f(12.5f, -1.5f, 0.0f);
        glVertex3f(15.0f, -2.5f, 0.0f);
        glVertex3f(15.0f, 0.5f, 0.0f);
        glEnd();
    }

    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex3f(11.0f, 2.5f, 0.0f);
    glVertex3f(12.0f, 2.5f, 0.0f);
    glVertex3f(12.0f, 0.5f, 0.0f);
    glVertex3f(11.0f, 0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(9.5f, 2.5f, 0.0f);
    glVertex3f(11.0f, 2.5f, 0.0f);
    glVertex3f(11.0f, 0.5f, 0.0f);
    glVertex3f(9.5f, 0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(7.5f, 2.5f, 0.0f);
    glVertex3f(9.0f, 2.5f, 0.0f);
    glVertex3f(9.0f, 0.5f, 0.0f);
    glVertex3f(7.5f, 0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(5.5f, 2.5f, 0.0f);
    glVertex3f(7.0f, 2.5f, 0.0f);
    glVertex3f(7.0f, 0.5f, 0.0f);
    glVertex3f(5.5f, 0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(3.5f, 2.5f, 0.0f);
    glVertex3f(5.0f, 2.5f, 0.0f);
    glVertex3f(5.0f, 0.5f, 0.0f);
    glVertex3f(3.5f, 0.5f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.5f, 2.5f, 0.0f);
    glVertex3f(3.0f, 2.5f, 0.0f);
    glVertex3f(3.0f, 0.5f, 0.0f);
    glVertex3f(1.5f, 0.5f, 0.0f);
    glEnd();

    glPopMatrix();
}

void updateCars(int value) {
    carX1 += carSpeed1;
    if (carX1 > 120.0f) carX1 = -30.0f;

    carX2 += carSpeed2;
    if (carX2 < -30.0f) carX2 = 120.0f;

    carX3 += carSpeed3;
    if (carX3 > 160.0f) carX3 = -40.0f;

    carX4 += carSpeed4;
    if (carX4 < -50.0f) carX4 = 150.0f;

    glutPostRedisplay();
    glutTimerFunc(30, updateCars, 0);
}

// Building drawing functions
void drawBuildingTop(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void deawSideBuildingTop(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawWindow(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void drawSideWindow(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void drawBuildingDoor(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}


// Draw day scene
void drawDayScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    drawRoads();
    roadBorder();

    drawSky(0.53f, 0.81f, 0.92f);
    drawSun(70,75, 2);

    //call clouds
    drawCloud(cloudX1, 75.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    drawCloud(cloudX2, 70.0f, 1.2f, 0.95f, 0.95f, 0.95f);
    drawCloud(cloudX3, 78.0f, 0.8f, 0.9f, 0.9f, 0.9f);

    //call planes
    drawPlane();
    drawPlane2(70.0f);


    //call cars and bus
    drawMiniCar();
    drawBlueBus();
    drawRedCar();



    glutSwapBuffers();
}

// Draw night scene
void drawNightScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    drawRoads();
    roadBorder();
    drawSky(0.08f, 0.08f, 0.25f);
    drawStars();
    drawCrescentMoon(10, 77, 2);

    //clouds
    drawCloud(cloudX1, 75.0f, 1.0f, 0.3f, 0.3f, 0.4f);
    drawCloud(cloudX2, 70.0f, 1.2f, 0.35f, 0.35f, 0.45f);
    drawCloud(cloudX3, 78.0f, 0.9f, 0.25f, 0.25f, 0.35f);

    //call planes
    drawPlane();
    drawPlane2(70.0f);

    //call cars and bus
    drawMiniCar();
    drawBlueBus();
    drawRedCar();

    glutSwapBuffers();
}

// Display callback
void display() {
    if (!isNight) {
        drawDayScene();
    }
    else {
        drawNightScene();
    }
}

// Keyboard handler to toggle day/night
void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'n' || key == 'N') {
        isNight = true;
        nightLight = true;
        glutPostRedisplay();
    }
    if (key == 'd' || key == 'D') {
        isNight = false;
        nightLight = false;
        glutPostRedisplay();
    }
    if (key == '2') {
        // click 2 to - increase speed
        planeSpeed = planeSpeed * 2;
        planeSpeed2 = planeSpeed2 * 2;
        carSpeed1 = 0.5 * 5;
        carSpeed2 = -0.4f * 2;
        carSpeed3 = 0.6f * 3;
        carSpeed4 = -0.5f * 4;
    }
    if (key == '3') {
        // click 3 to  - decrease speed
        planeSpeed = planeSpeed / 2;
        planeSpeed2 = planeSpeed2 / 2;
        carSpeed1 = 0.5 / 5;
        carSpeed2 = -0.4f / 2;
        carSpeed3 = 0.6f / 3;
        carSpeed4 = -0.5f / 4;
    }

    if (key == '4') {
        //Click 3 - reset to normal speed
        planeSpeed = 0.2f * 2;
        planeSpeed2 = 0.4;
        carSpeed1 = 0.5;
        carSpeed2 = -0.4f;
        carSpeed3 = 0.6f;
        carSpeed4 = -0.5f;

    }
}

// Mouse handler
void handleMouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            // Left click - increase speed
            planeSpeed = planeSpeed * 2;
            planeSpeed2 = planeSpeed2 * 2;
            carSpeed1 = 0.5 * 5;
            carSpeed2 = -0.4f * 2;
            carSpeed3 = 0.6f * 3;
            carSpeed4 = -0.5f * 4;
        }
        else if (button == GLUT_RIGHT_BUTTON) {
            // Right click - decrease speed
            planeSpeed = planeSpeed / 2;
            planeSpeed2 = planeSpeed2 / 2;
            carSpeed1 = 0.5 / 5;
            carSpeed2 = -0.4f / 2;
            carSpeed3 = 0.6f / 3;
            carSpeed4 = -0.5f / 4;
        }
        else if (button == GLUT_MIDDLE_BUTTON) {
            // Middle click - reset to normal speed
            planeSpeed = 0.2f * 2;
            planeSpeed2 = 0.4;
            carSpeed1 = 0.5;
            carSpeed2 = -0.4f;
            carSpeed3 = 0.6f;
            carSpeed4 = -0.5f;
        }
    }
    glutPostRedisplay();
}

// Initialization
void initRendering() {
    glClearColor(0.5, 0.5, 0.5, 0.5);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

// Resize handler
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 80.0);
    glMatrixMode(GL_MODELVIEW);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("City View 2D - Day/Night Scene");

    initRendering();
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutReshapeFunc(handleResize);

    glutTimerFunc(0, updateClouds, 0);
    glutTimerFunc(0, updateCars, 0);
    glutTimerFunc(0, updatePlane, 0);

    glutMainLoop();
    return 0;
}
