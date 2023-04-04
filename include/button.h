#ifndef BUTTON_H_INCLUDED_
#define BUTTON_H_INCLUDED_


#include <stdbool.h>

#include "point.h"
#include "rect.h"
#include "color.h"


extern const Color default_color;
extern const Color hovered_color;
extern const Color pressed_color;
extern const Color border_color;


/**
 * Structure which stores data associated with some button
 * such as its rectangle and text and also buttons conditions
 * such as is it hovered or pressed.
 */
typedef struct button
{
    char *text;

    Rect rect;

    bool is_hovered;
    bool is_pressed;
} Button;


/**
 * Function which is called after mouse left button press
 * at the given @a position and handles it for the given @a button.
 */
void buttonMouseLeftDown(Button *button, Point position);

/**
 * Function which is called after mouse left button release
 * at the given @a position and handles it for the given @a button.
 */
void buttonMouseLeftUp(Button *button, Point position);

/**
 * Function which is called after mouse move
 * to the given @a position and handles it for the given @a button.
 */
void buttonMouseMove(Button *button, Point position);


#endif  /* BUTTON_H_INCLUDED_ */
