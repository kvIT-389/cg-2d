#include <GL/gl.h>

#include "draw.h"
#include "mainwindow.h"
#include "rect.h"
#include "button.h"
#include "color.h"
#include "menu.h"
#include "mainmenu.h"
#include "texture.h"


double angle = 0.0;
double scale = 1.0;

Rect rct = {0, 0, 256, 256};
double texture_coords[] = {0.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0};


void draw(void)
{
    glPushMatrix();
        glOrtho(0, main_window.size.width, 0, main_window.size.height, -1.0, 1.0);

        drawTexturedRect(&rct, &test_texture, 0);
    glPopMatrix();

    drawMenu(&main_menu);
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
    _coord_t vertices[] = {
        0, 0, rect->width, 0,
        rect->width, rect->height, 0, rect->height
    };
    glVertexPointer(2, GL_INT, 0, vertices);

    glPushMatrix();
    glEnableClientState(GL_VERTEX_ARRAY);
        glTranslated(rect->x, rect->y, 0.0);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
}

void drawTexturedRect(
    const Rect *rect,
    const Texture *texture,
    const Rect *texture_rect
)
{
    glBindTexture(GL_TEXTURE_2D, texture->id);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glColor4ub(0xff, 0xff, 0xff, 0xff);
    glTexCoordPointer(2, GL_DOUBLE, 0, texture_coords);

    drawRect(rect);

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glBindTexture(GL_TEXTURE_2D, 0);
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
    else if (button->is_hovered) {
        setColor(&hovered_color);
    }
    else {
        setColor(&default_color);
    }

    drawRect(&inset_rect);

    glPopMatrix();
}

void drawMenu(const Menu *menu)
{
    glPushMatrix();

    glLoadIdentity();
    glOrtho(
        0, main_window.size.width,
        main_window.size.height, 0,
        -1.0, 1.0
    );

    for (int i = 0; i < menu->buttons_count; ++i) {
        drawButton(menu->buttons + i);
    }

    glPopMatrix();
}
