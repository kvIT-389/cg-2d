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

Rect rct;


void draw(void)
{
    glPushMatrix();

    rct = getRect(
        (Point){0, main_window.size.height - 256},
        (Size){256, 256}
    );

    glOrtho(
        0, main_window.size.width,
        main_window.size.height, 0,
        -1.0, 1.0
    );

    drawTexturedRect(&rct, &test_texture, 0);
    drawMenu(&main_menu);

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
    glVertexPointer(2, GL_INT, 0, rect->vertices);

    glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void drawRectFrame(const Rect *rect, GLfloat line_width)
{
    glVertexPointer(2, GL_INT, 0, rect->vertices);

    glEnableClientState(GL_VERTEX_ARRAY);
        glLineWidth(line_width);
        glDrawArrays(GL_LINE_LOOP, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

}

void drawTexturedRect(
    const Rect *rect,
    const Texture *texture,
    const Rect *texture_rect
)
{
    if (!texture->id) return;  /* Error: texture is not loaded. */

    Rect full_texture_rect;

    if (!texture_rect) {
        full_texture_rect = getRect((Point){0, 0}, texture->size);

        texture_rect = &full_texture_rect;
    }

    double texture_coords[8];
    for (int i = 0; i < 8; i += 2) {
        texture_coords[i] = texture_rect->vertices[i >> 1].x
                          / (double)texture->size.width;
    }

    for (int i = 1; i < 8; i += 2) {
        texture_coords[i] = texture_rect->vertices[i >> 1].y
                          / (double)texture->size.height;
    }


    glBindTexture(GL_TEXTURE_2D, texture->id);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    setCurrentColor(&white);
    glTexCoordPointer(2, GL_DOUBLE, 0, texture_coords);

    drawRect(rect);

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glBindTexture(GL_TEXTURE_2D, 0);
}


void drawButton(const Button *button)
{
    glPushMatrix();

    if (button->is_pressed) {
        setCurrentColor(&pressed_color);
    }
    else if (button->is_hovered) {
        setCurrentColor(&hovered_color);
    }
    else {
        setCurrentColor(&default_color);
    }

    drawRect(&button->rect);

    setCurrentColor(&border_color);
    drawRectFrame(&button->rect, 2.0f);

    glPopMatrix();
}

void drawMenu(const Menu *menu)
{
    glPushMatrix();

    for (int i = 0; i < menu->buttons_count; ++i) {
        drawButton(menu->buttons + i);
    }

    glPopMatrix();
}
