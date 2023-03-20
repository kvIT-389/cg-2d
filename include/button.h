#ifndef BUTTON_H_INCLUDED_
#define BUTTON_H_INCLUDED_


#include <stdbool.h>

#include "rect.h"
#include "color.h"


extern const Color default_color;
extern const Color hovered_color;
extern const Color pressed_color;
extern const Color border_color;


typedef struct button
{
    char text[100];

    Rect rect;

    bool is_hovered;
    bool is_pressed;
} Button;


#endif  /* BUTTON_H_INCLUDED_ */
