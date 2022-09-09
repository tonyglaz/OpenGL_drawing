#include <stdlib.h>
#include <glut.h>
#include <iostream>
#include <ctime>
#include <math.h>
#define PI 3.14159265
using namespace std;

#define SIZE 1000

GLfloat yRotated = -30;
GLfloat xRotated, zRotated = 0.0;
GLfloat zTranslated = 2.0;

GLdouble innerRaidus = 0.05;
GLdouble outterRaidus = 0.18;
GLint sides = 1000;
GLint rings = 50;


GLfloat mat_shininess = 0.1 * 128.0;
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_ambient[] = { 1.0,1.0,1.0,1.0 };
GLfloat mat_diffuse[] = { 1.0,1.0,1.0,1.0 };




double fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

GLdouble R = 0.8;
GLdouble G = 0.5;
GLdouble B = 0.1;

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius) {
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y, z); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex3f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)), z);
    }
    glEnd();
}

void drawHead() {
    //skull
    glPushMatrix();
    glTranslatef(0.0, 0.1, 0.0);
    glScalef(1.0, 0.8, 0.9);
    glutSolidSphere(outterRaidus * 0.7, 150, 150);
    glPopMatrix();

    //ears
    glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);
    glColor3f(R, G, B);

    glVertex3f(-0.11, 0.15, 0.0);
    glVertex3f(-0.07, 0.25, -0.05);
    glVertex3f(-0.07, 0.15, -0.05);

    glVertex3f(-0.07, 0.15, -0.05);
    glVertex3f(-0.07, 0.25, -0.05);
    glVertex3f(-0.03, 0.15, 0.0);

    glColor3f(1.0, 1.0, 1.0);

    glVertex3f(-0.1, 0.15, 0.0);
    glVertex3f(-0.07, 0.22, -0.04);
    glVertex3f(-0.07, 0.15, -0.04);

    glVertex3f(-0.07, 0.15, -0.04);
    glVertex3f(-0.07, 0.22, -0.04);
    glVertex3f(-0.04, 0.15, 0.0);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);
    glColor3f(R, G, B);

    glVertex3f(0.11, 0.15, 0.0);
    glVertex3f(0.07, 0.25, -0.05);
    glVertex3f(0.07, 0.15, -0.05);

    glVertex3f(0.07, 0.15, -0.05);
    glVertex3f(0.07, 0.25, -0.05);
    glVertex3f(0.03, 0.15, 0.0);

    glColor3f(1.0, 1.0, 1.0);

    glVertex3f(0.1, 0.15, 0.0);
    glVertex3f(0.07, 0.22, -0.04);
    glVertex3f(0.07, 0.15, -0.04);

    glVertex3f(0.07, 0.15, -0.04);
    glVertex3f(0.07, 0.22, -0.04);
    glVertex3f(0.04, 0.15, 0.0);

    glEnd();
    glPopMatrix();

    //nose
    glColor3f(0.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0, 0.1, 0.117);
    glScalef(0.1, 0.1, 0.1);
    glutSolidSphere(outterRaidus * 0.3, 150, 150);
    glPopMatrix();

    glBegin(GL_LINES);
    glVertex3f(0.0, 0.1, 0.117);
    glVertex3f(-0.07, 0.12, 0.117);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0, 0.1, 0.117);
    glVertex3f(-0.075, 0.11, 0.117);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0, 0.1, 0.117);
    glVertex3f(-0.072, 0.095, 0.117);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0, 0.1, 0.117);
    glVertex3f(0.07, 0.12, 0.117);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0, 0.1, 0.117);
    glVertex3f(0.075, 0.11, 0.117);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.0, 0.1, 0.117);
    glVertex3f(0.072, 0.095, 0.117);
    glEnd();

    //eyes
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-0.03, 0.13, 0.07);
    glutSolidSphere(outterRaidus * 0.2, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.03, 0.13, 0.07);
    glutSolidSphere(outterRaidus * 0.2, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(-0.03, 0.14, 0.09);
    glutSolidSphere(outterRaidus * 0.1, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.03, 0.14, 0.09);
    glutSolidSphere(outterRaidus * 0.1, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-0.03, 0.145, 0.1);
    glutSolidSphere(outterRaidus * 0.05, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.03, 0.145, 0.1);
    glutSolidSphere(outterRaidus * 0.05, 150, 150);
    glPopMatrix();

    //mouth
    glBegin(GL_LINE_STRIP);
    glVertex3f(-0.03, 0.08, 0.117);
    glVertex3f(-0.02, 0.06, 0.117);
    glVertex3f(0.0, 0.08, 0.117);
    glVertex3f(0.02, 0.06, 0.117);
    glVertex3f(0.03, 0.08, 0.117);
    glEnd();

}

void drawTorso() {
    //torso
    glPushMatrix();
    glColor3f(R, G, B);
    glTranslatef(0.0, 0.0, -0.2);
    glScalef(0.7, 0.7, 1.7);
    glutSolidSphere(outterRaidus * 0.7, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, 0.0, -0.165);
    glScalef(0.62, 0.65, 1.5);
    glutSolidSphere(outterRaidus * 0.7, 150, 150);
    glPopMatrix();

    //tail
    glPushMatrix();
    glColor3f(R, G, B);
    glRotatef(45, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.3, -0.35);
    glScalef(0.4, 0.3, 1.0);
    glutSolidSphere(outterRaidus * 0.7, 150, 150);
    glPopMatrix();

}

void drawLegs() {
    //forward legs
    glPushMatrix();
    glColor3f(R, G, B);
    glTranslatef(0.07, -0.05, -0.07);
    glScalef(0.15, 0.6, 0.17);
    glutSolidSphere(outterRaidus, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.07, -0.14, -0.07);
    glScalef(0.1, 0.1, 0.1);
    glutSolidSphere(outterRaidus, 150, 150);
    glPopMatrix();

    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(0.065 + 0.01 * i, -0.15, -0.052);
        glScalef(0.05, 0.05, 0.05);
        glutSolidSphere(outterRaidus, 150, 150);
        glPopMatrix();
    }

    glPushMatrix();
    glColor3f(R, G, B);
    glTranslatef(-0.07, -0.05, -0.07);
    glScalef(0.15, 0.6, 0.17);
    glutSolidSphere(outterRaidus, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-0.07, -0.14, -0.07);
    glScalef(0.1, 0.1, 0.1);
    glutSolidSphere(outterRaidus, 150, 150);
    glPopMatrix();

    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(-0.065 - 0.01 * i, -0.15, -0.052);
        glScalef(0.05, 0.05, 0.05);
        glutSolidSphere(outterRaidus, 150, 150);
        glPopMatrix();
    }

    // backward legs
    glPushMatrix();
    glColor3f(R, G, B);
    glTranslatef(0.04, -0.06, -0.35);
    glScalef(0.15, 0.6, 0.17);
    glutSolidSphere(outterRaidus, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.04, -0.15, -0.35);
    glScalef(0.1, 0.1, 0.1);
    glutSolidSphere(outterRaidus, 150, 150);
    glPopMatrix();

    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(0.035 + 0.01 * i, -0.16, -0.33);
        glScalef(0.05, 0.05, 0.05);
        glutSolidSphere(outterRaidus, 150, 150);
        glPopMatrix();
    }

    glPushMatrix();
    glColor3f(R, G, B);
    glTranslatef(-0.04, -0.06, -0.35);
    glScalef(0.15, 0.6, 0.17);
    glutSolidSphere(outterRaidus, 150, 150);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-0.04, -0.15, -0.35);
    glScalef(0.1, 0.1, 0.1);
    glutSolidSphere(outterRaidus, 150, 150);
    glPopMatrix();

    for (int i = 0; i < 3; i++) {
        glPushMatrix();
        glColor3f(1.0, 1.0, 1.0);
        glTranslatef(-0.035 - 0.01 * i, -0.16, -0.33);
        glScalef(0.05, 0.05, 0.05);
        glutSolidSphere(outterRaidus, 150, 150);
        glPopMatrix();
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

    /*if (rand() % 100 > 90) {
        R = fRand(0.0, 1.0);
        G = fRand(0.0, 1.0);
        B = fRand(0.0, 1.0);
    }*/

    glColor3f(R, G, B);
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated, 1.0, 0.0, 0.0);
    // rotation about Y axis
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    // rotation about Z axis
    glRotatef(zRotated, 0.0, 0.0, 1.0);
    // scaling transfomation 
    //glScalef(1.0, 1.0, 1.0);
    drawHead();

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
        // Name	Ambient	Diffuse	Specular	Shininess
         //    emerald	0.0215	0.1745	0.0215	0.07568	0.61424	0.07568	0.633	0.727811	0.633	0.6
    case GLUT_KEY_F1:
        mat_shininess = 0.6 * 128.0;
        mat_specular[0] = 0.633;
        mat_specular[1] = 0.727811;
        mat_specular[2] = 0.633;
        mat_ambient[0] = 0.0215;
        mat_ambient[1] = 0.1745;
        mat_ambient[2] = 0.0215;
        mat_diffuse[0] = 0.07568;
        mat_diffuse[1] = 0.61424;
        mat_diffuse[2] = 0.07568;
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_shininess);
        glutPostRedisplay();
        break;

        // jade
    case GLUT_KEY_F2:
        mat_shininess = 0.1 * 128.0;
        mat_specular[0] = 0.316228;
        mat_specular[1] = 0.316228;
        mat_specular[2] = 0.316228;
        mat_ambient[0] = 0.135;
        mat_ambient[1] = 0.2225;
        mat_ambient[2] = 0.1575;
        mat_diffuse[0] = 0.54;
        mat_diffuse[1] = 0.89;
        mat_diffuse[2] = 0.63;
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_shininess);
        glutPostRedisplay();
        break;

        //obsidian
    case GLUT_KEY_F3:
        mat_shininess = 0.3 * 128.0;
        mat_specular[0] = 0.332741;
        mat_specular[1] = 0.328634;
        mat_specular[2] = 0.346435;
        mat_ambient[0] = 0.05375;
        mat_ambient[1] = 0.05;
        mat_ambient[2] = 0.06625;
        mat_diffuse[0] = 0.18275;
        mat_diffuse[1] = 0.17;
        mat_diffuse[2] = 0.22525;
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_shininess);
        glutPostRedisplay();
        break;
        //pearl
    case GLUT_KEY_F4:
        mat_shininess = 0.088 * 128.0;
        mat_specular[0] = 0.296648;
        mat_specular[1] = 0.296648;
        mat_specular[2] = 0.296648;
        mat_ambient[0] = 0.25;
        mat_ambient[1] = 0.20725;
        mat_ambient[2] = 0.20725;
        mat_diffuse[0] = 1;
        mat_diffuse[1] = 0.829;
        mat_diffuse[2] = 0.829;
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_shininess);
        glutPostRedisplay();
        break;
        //red plastic
    case GLUT_KEY_F5:
        mat_shininess = .25 * 128.0;
        mat_specular[0] = 0.7;
        mat_specular[1] = 0.6;
        mat_specular[2] = 0.6;
        mat_ambient[0] = 0.0;
        mat_ambient[1] = 0.0;
        mat_ambient[2] = 0.0;
        mat_diffuse[0] = 0.5;
        mat_diffuse[1] = 0.0;
        mat_diffuse[2] = 0.0;
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_shininess);
        glutPostRedisplay();
        break;
        //gold
    case GLUT_KEY_F6:
        mat_shininess = 0.4 * 128.0;
        mat_specular[0] = 0.628281;
        mat_specular[1] = 0.555802;
        mat_specular[2] = 0.366065;
        mat_ambient[0] = 0.24725;
        mat_ambient[1] = 0.1995;
        mat_ambient[2] = 0.0745;
        mat_diffuse[0] = 0.75164;
        mat_diffuse[1] = 0.60648;
        mat_diffuse[2] = 0.22648;
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_shininess);
        glutPostRedisplay();
        break;
        //chrome
    case GLUT_KEY_F7:
        mat_shininess = 0.6 * 128.0;
        mat_specular[0] = 0.774597;
        mat_specular[1] = 0.774597;
        mat_specular[2] = 0.774597;
        mat_ambient[0] = 0.25;
        mat_ambient[1] = 0.25;
        mat_ambient[2] = 0.25;
        mat_diffuse[0] = 0.4;
        mat_diffuse[1] = 0.4;
        mat_diffuse[2] = 0.4;
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_shininess);
        glutPostRedisplay();
        break;
    }
}




void myinit()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_LINE_SMOOTH);
    glClearColor(0.2, 0.2, 0.2, 0.0);
    glutReshapeFunc(reshape);
    //glutIdleFunc(idle);
    //Let start glut loop
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, mat_ambient);
    glEnable(GL_LIGHT0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &mat_shininess);
    GLfloat pos[] = { 1, 0, 0, 1 };
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glEnable(GL_COLOR_MATERIAL);


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
    glutCreateWindow("Cat Rotating Animation");
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_LINE_SMOOTH);
    glClearColor(0.2, 0.2, 0.2, 0.0);
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