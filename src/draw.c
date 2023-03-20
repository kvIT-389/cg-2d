#include <GL/gl.h>

#include "draw.h"
#include "mainwindow.h"
#include "rect.h"
#include "button.h"
#include "color.h"


double angle = 0.0;
double scale = 1.0;

Button test_button = {"Test Button", {10, 10, 80, 30}};


void draw(void)
{
    glPushMatrix();
        glLoadIdentity();
        glOrtho(0, main_window.size.width, main_window.size.height, 0, -1.0, 1.0);
        drawButton(&test_button);
    glPopMatrix();
}

void drawHexagon(void)
{
    glPushMatrix();

    double k = (double)(main_window.size.width) /
               (double)(main_window.size.height);
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

void drawRect(const Rect *rect)
{
    glPushMatrix();

    glTranslated(rect->x, rect->y, 0.0);
    glRecti(
        0.0, 0.0, rect->width, rect->height
    );

    glPopMatrix();
}

void drawButton(const Button *button)
{
    Rect rect = button->rect;

    Rect inset_rect = {
        rect.x + 2, rect.y + 2,
        rect.width - 2*2, rect.height - 2*2
    };

    glPushMatrix();

    setColor(&border_color);
    drawRect(&rect);

    if (button->is_pressed) {
        setColor(&pressed_color);
    }
    else if (test_button.is_hovered) {
        setColor(&hovered_color);
    }
    else {
        setColor(&default_color);
    }

    drawRect(&inset_rect);

    glPopMatrix();
}
