#include <GL/gl.h>

#include "draw.h"
#include "mainwindow.h"


double angle = 0.0;
double scale = 1.0;


void draw(void)
{
    drawHexagon();
}

void drawHexagon(void)
{
    glPushMatrix();

    double k = (main_window.width) / (double)(main_window.height);
    if (k > 1.0) {
        glOrtho(-k, k, -1.0, 1.0, -1.0, 1.0);
    }
    else {
        glOrtho(-1.0, 1.0, -1.0/k, 1.0/k, -1.0, 1.0);
    }

    glRotated(angle, 0.0, 0.0, 1.0);
    glScaled(scale, scale, 1.0);

    glBegin(GL_POLYGON);
        glColor3ub(0xff, 0x00, 0x00);  glVertex2d( 1.0,  0.0);
        glColor3ub(0xff, 0xff, 0x00);  glVertex2d( 0.5,  0.87);
        glColor3ub(0x00, 0xff, 0x00);  glVertex2d(-0.5,  0.87);
        glColor3ub(0x00, 0xff, 0xff);  glVertex2d(-1.0,  0.0);
        glColor3ub(0x00, 0x00, 0xff);  glVertex2d(-0.5, -0.87);
        glColor3ub(0xff, 0x00, 0xff);  glVertex2d( 0.5, -0.87);
    glEnd();

    glPopMatrix();
}
