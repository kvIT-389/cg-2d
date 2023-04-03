#ifndef DRAW_H_INCLUDED_
#define DRAW_H_INCLUDED_


#include "texture.h"
#include "button.h"
#include "menu.h"


extern double angle;
extern double scale;


/**
 * Current window main drawing function.
 */
void draw(void);

/**
 * Draws RGB hexagon rotated on angle.
 */
void drawHexagon(void);

/**
 * Draws rectangle specified by @a rect, and using current color.
 */
void drawRect(const Rect *rect);

/**
 * Draws ...
 */
void drawTexturedRect(
    const Rect *rect,
    const Texture *texture,
    const Rect *texture_rect
);

/**
 * Draws button specified by @a button.
 */
void drawButton(const Button *button);

/**
 * Draws menu specified by @a menu.
 */
void drawMenu(const Menu *menu);


#endif  /* DRAW_H_INCLUDED_ */
