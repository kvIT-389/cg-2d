#include <GL/gl.h>
#include <GL/glut.h>

#include "draw.h"


double angle = 0.0;


void draw(void)
{
    drawHexagon();
}

void drawHexagon(void)
{
    glPushMatrix();

    glRotated(angle, 0.0, 0.0, 1.0);

    glBegin(GL_POLYGON);
        glColor3ub(0xff, 0x00, 0x00);  glVertex2d( 1.0,  0.0);
        glColor3ub(0xff, 0xff, 0x00);  glVertex2d( 0.5,  0.87);
        glColor3ub(0x00, 0xff, 0x00);  glVertex2d(-0.5,  0.87);
        glColor3ub(0x00, 0xff, 0xff);  glVertex2d(-1.0,  0.0);
        glColor3ub(0x00, 0x00, 0xff);  glVertex2d(-0.5, -0.87);
        glColor3ub(0xff, 0x00, 0xff);  glVertex2d( 0.5, -0.87);
        glColor3ub(0xff, 0x00, 0x00);  glVertex2d( 1.0,  0.0);
    glEnd();

    glPopMatrix();
}
