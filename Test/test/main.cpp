#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float _angle_2 = 90;
float i = 0.0f;
float _move = -1.5;

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(0.53, 0.808, 0.92,0);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -3.0); //Move forward 5 units

    glPushMatrix();
    glColor3f(.99,0.87,0.13);
    glTranslatef(1.2,_move,0.0);
    glRotatef(0,0.0,0.0,0.0);
    glutSolidSphere(.20,20,20); //(GLdouble radius,GLint slices, GLint stacks);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.82,0.76,.725);
    glTranslatef(-1,-0.4,0.0);
    glScalef(2,1.5,1);
    glRotatef(30,2.0,30.0,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.48,0.38,0.33);
    glTranslatef(-.95,-.13,0);
    glRotatef(-95,180,5,0);
    glutSolidCone(.8,.45,16,8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(.66,0.34,.13);
    glTranslatef(-.78,-0.525,0.0);
    glScalef(.5,1,1);
    glRotatef(12,0.0,90.0,0.0);
    glutSolidCube(.5); //(GLdouble size)
    glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_move += 0.02;
	if(_move > 0.8){ _move = 0.8; }

	glutPostRedisplay(); //Tell GLUT that the display has changed
	glutTimerFunc(25, update, 0);
}

void handleResize(int w, int h) {
    glEnable(GL_DEPTH_TEST);

    /* turn on default lighting */
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluLookAt(5.0,2.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 600);
	glutCreateWindow("Playing");
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer
	glutMainLoop();
	return 0;
}
