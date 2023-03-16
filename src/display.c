#include <GL/gl.h>
#include <GL/glut.h>

#include "display.h"


double angle = 0.0;


void drawHexagon(void)
{
    glPushMatrix();

    glRotated(angle, 0.0, 0.0, 1.0);

    glBegin(GL_POLYGON);
        glColor3ub(0xff, 0x00, 0x00);  glVertex2d( 1.0,  0.0);
        glColor3ub(0x7f, 0x7f, 0x00);  glVertex2d( 0.5,  0.87);
        glColor3ub(0x00, 0xff, 0x00);  glVertex2d(-0.5,  0.87);
        glColor3ub(0x00, 0x7f, 0x7f);  glVertex2d(-1.0,  0.0);
        glColor3ub(0x00, 0x00, 0xff);  glVertex2d(-0.5, -0.87);
        glColor3ub(0x7f, 0x00, 0x7f);  glVertex2d( 0.5, -0.87);
    glEnd();

    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    drawHexagon();

    if (glutGet(GLUT_WINDOW_DOUBLEBUFFER)) {
        glutSwapBuffers();
    }
    else {
        glFlush();
    }
}
