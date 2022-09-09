#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include <ctime>
#include <math.h>
#define PI 3.14159265
using namespace std;

#define SIZE 1000

GLfloat xRotated, zRotated = 0.0;
GLfloat yRotated = -25.0;
GLfloat zTranslated = 0.0;

GLdouble innerRaidus = 0.05;
GLdouble outterRaidus = 0.18;
GLint sides = 1000;
GLint rings = 50;

double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

GLdouble R = 0.4;
GLdouble G = 0.8;
GLdouble B = 0.4;

void drawHead() {
    //skull
    glPushMatrix();
    glColor3f(R, G, B);
    glTranslatef(0.0, 0.0, -0.4);
    glutSolidSphere(outterRaidus * 1.25, 150, 150);
    glPopMatrix();

    //ears
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-0.1, 0.1, -0.4);
    glRotatef(15, 0.0, 0.0, 1.0);
    glScalef(0.1, 1.5, 0.1);
    glutSolidSphere(outterRaidus, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.1, 0.1, -0.4);
    glRotatef(-15, 0.0, 0.0, 1.0);
    glScalef(0.1, 1.5, 0.1);
    glutSolidSphere(outterRaidus, 150, 150);
    glPopMatrix();

    //eyes
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-0.07, 0.1, -0.25);
    glutSolidSphere(outterRaidus * 0.3, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-0.07, 0.1, -0.2);
    glutSolidSphere(outterRaidus * 0.1, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.07, 0.1, -0.25);
    glutSolidSphere(outterRaidus * 0.3, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.07, 0.1, -0.2);
    glutSolidSphere(outterRaidus * 0.1, 150, 150);
    glPopMatrix();

    //mouth
    glPushMatrix();
    glColor3f(1.0, 0.4, 0.4);
    glTranslatef(0.0, -0.05, -0.17);
    glScalef(1.0, 0.5, 1.0);
    glutSolidTorus(innerRaidus * 0.15, outterRaidus / 5, sides, rings);
    glPopMatrix();

    //nose
    glPushMatrix();
    glColor3f(1.0, 0.4, 0.4);
    glTranslatef(0.0, 0.05, -0.17);
    glutSolidSphere(outterRaidus * 0.1, 150, 150);
    glPopMatrix();
}

void drawTorso(int number_of_parts) {
    glColor3f(R, G, B);
    double z_pos = -0.5;
    double part_size_coeff = (1.0 - 0.6) / number_of_parts;

    for (int i = 0; i < number_of_parts; i++) {
        glPushMatrix();
        glColor3f(R, G, B);
        glTranslatef(0.0, 0.0, z_pos * (1.5 - part_size_coeff * double(i)));
        glutSolidSphere(outterRaidus * (1.0 - part_size_coeff * double(i)), 150, 150);
        glPopMatrix();

        //left legs
        glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(-0.115 + part_size_coeff * i / number_of_parts, -0.125, z_pos * (1.5 - part_size_coeff * double(i)));
        glRotatef(-15, 0.0, 0.0, 1.0);
        glScalef(0.2 - part_size_coeff * i / number_of_parts, 0.5 - part_size_coeff * i / number_of_parts, 0.2 - part_size_coeff * i / number_of_parts);
        glutSolidSphere(outterRaidus * (1.0 - part_size_coeff * double(i)), 150, 150);
        glPopMatrix();

        //right legs
        glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        glTranslatef(0.115 - part_size_coeff * i / number_of_parts, -0.125, z_pos * (1.5 - part_size_coeff * double(i)));
        glRotatef(15, 0.0, 0.0, 1.0);
        glScalef(0.2 - part_size_coeff * i / number_of_parts, 0.5 - part_size_coeff * i / number_of_parts, 0.2 - part_size_coeff * i / number_of_parts);
        glutSolidSphere(outterRaidus * (1.0 - part_size_coeff * double(i)), 150, 150);
        glPopMatrix();

        z_pos -= 0.25;
    }

}

void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0, 0.0, -4.0 + zTranslated);

    glColor3f(R, G, B);
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated, 1.0, 0.0, 0.0);
    // rotation about Y axis
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    // rotation about Z axis
    glRotatef(zRotated, 0.0, 0.0, 1.0);
    // scaling transfomation 

    drawHead();
    drawTorso(5);

    // Flush buffers to screen
    //glFlush();
    // swap buffers called because we are using double buffering 
    glutSwapBuffers();
}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);

    glViewport(0, 0, x, y);  //Use the whole window for rendering
}

void idle(void)
{
    int rotation = rand() % 3;
    int direction = 1;
    //if (rand() % 2)
        //direction = -1;

    switch (rotation) {
    case 0:
        yRotated = fmod(yRotated + direction * 0.15, 360);
        break;
    case 1:
        xRotated = fmod(xRotated + direction * 0.15, 360);
        break;
    case 2:
        zRotated = fmod(zRotated + direction * 0.15, 360);
        break;
    }

    display();
}

void processNormalKeys(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
    else if (key == '+') {
        zTranslated += 0.2;
        display();
    }
    else if (key == '-') {
        zTranslated -= 0.2;
        display();
    }
}

void processSpecialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        //if (abs(abs(angle) - 360.0f) <= 0.1f)
            //angle = 0.0f;
        //else
        yRotated -= 0.5f;
        display();
        break;
    case GLUT_KEY_RIGHT:
        //if (abs(abs(angle) - 360.0f) <= 0.1f)
            //angle = 0.0f;
        //else
        yRotated += 0.5f;
        display();
        break;

    case GLUT_KEY_UP:
        //if (abs(abs(angle) - 360.0f) <= 0.1f)
            //angle = 0.0f;
        //else
        xRotated += 0.5f;
        display();
        break;
    case GLUT_KEY_DOWN:
        //if (abs(abs(angle) - 360.0f) <= 0.1f)
            //angle = 0.0f;
        //else
        xRotated -= 0.5f;
        display();
        break;
    case GLUT_KEY_PAGE_UP:
        //if (abs(abs(angle) - 360.0f) <= 0.1f)
            //angle = 0.0f;
        //else
        zRotated += 0.5f;
        display();
        break;
    case GLUT_KEY_PAGE_DOWN:
        //if (abs(abs(angle) - 360.0f) <= 0.1f)
            //angle = 0.0f;
        //else
        zRotated -= 0.5f;
        display();
        break;
    }
}

double lightX = 0;
double lightSpeed = 0.02;

double lightX1 = 0;
double lightSpeed1 = 0.02;

void timer(int val) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    lightX += lightSpeed;
    if (abs(lightX) >= 1) {
        lightSpeed = -lightSpeed;
        lightX += lightSpeed;
    }
    GLfloat pos[] = { lightX,lightX, 0, 1 };
    glLightfv(GL_LIGHT0, GL_POSITION, pos);


    lightX1 += lightSpeed1;
    if (abs(lightX1) >= 1) {
        lightSpeed1 = -lightSpeed1;
        lightX1 += lightSpeed1;
    }
    GLfloat pos1[] = { -lightX1,lightX1, 0, 1 };
    glLightfv(GL_LIGHT1, GL_POSITION, pos1);
}

float ambient[] = { 1.0,1.0,1.0,1.0 };

void myinit()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_LINE_SMOOTH);
    glClearColor(0.2, 0.2, 0.2, 0.0);
    glutReshapeFunc(reshape);
    //glutIdleFunc(idle);
    //Let start glut loop
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);


    GLfloat pos[] = { 1, 0, 0, 1 };
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat pos1[] = { 1, 0, 0, 1 };
    GLfloat KEK[] = { 1, 1, 1, 1 };
    glLightfv(GL_LIGHT1, GL_POSITION, KEK);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, KEK);
    glLightfv(GL_LIGHT1, GL_SPECULAR, pos1);
    glutTimerFunc(1000 / 60, timer, 0);
}

int main(int argc, char** argv)
{
    srand(time(NULL));
    //Initialize GLUT
    glutInit(&argc, argv);
    //double buffering used to avoid flickering problem in animation
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    // window size and position
    glutInitWindowSize(SIZE, SIZE);
    glutInitWindowPosition(0, 0);
    // create the window 
    glutCreateWindow("Caterpillar Rotating Animation");
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_LINE_SMOOTH);
    glClearColor(0.5, 0.4, 0.5, 0.0);
    //Assign  the function used in events
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    //glutIdleFunc(idle);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    //Let start glut loop
    glEnable(GL_DEPTH_TEST);
    myinit();
    glutMainLoop();
    return 0;
}