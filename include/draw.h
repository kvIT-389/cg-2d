#ifndef DRAW_H_INCLUDED_
#define DRAW_H_INCLUDED_


#include "types.h"
#include "rect.h"
#include "texture.h"
#include "button.h"
#include "menu.h"


extern double angle;
extern double scale;


/**
 * Current window main drawing function.
 * Called each time @a display function called.
 */
void draw(void);

/**
 * Draws RGB hexagon rotated on angle.
 */
void drawHexagon(void);

/**
 * Draws rectangle specified by @a rect
 * using current color.
 */
void drawRect(const Rect *rect);

/**
 * Draws rectangle frame specified by @a rect
 * using current color and the given @a line_width.
 */
void drawRectFrame(const Rect *rect, _line_width_t line_width);

/**
 * Draws texture in the rectangle specified by @a rect
 * using data from @a texture.
 * 
 * Rectangle @a texture_rect specifies area of the texture
 * which is used to draw and depends on texture size.
 * 
 * To use all texture data @a texture_rect pointer
 * should be equal to @c NULL:
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
