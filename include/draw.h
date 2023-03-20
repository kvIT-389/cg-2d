#ifndef DRAW_H_INCLUDED_
#define DRAW_H_INCLUDED_


#include "button.h"


extern double angle;
extern double scale;

extern Button test_button;


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
 * Draws button specified by @a button.
 */
void drawButton(const Button *button);


#endif  /* DRAW_H_INCLUDED_ */
