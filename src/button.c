#include <stdio.h>

#include "button.h"

#include "color.h"
#include "collision.h"


const Color default_color = {0xe0, 0xe0, 0xe0};
const Color hovered_color = {0xd0, 0xd0, 0xd0};
const Color pressed_color = {0xb0, 0xb0, 0xb0};
const Color border_color  = {0x70, 0x70, 0x70};


void buttonMouseLeftDown(Button *button, const Point pos)
{
    if (pointInRect(&pos, &button->rect)) {
        button->is_pressed = true;
        printf("%s pressed.\n", button->text);
    }
}

void buttonMouseLeftUp(Button *button, const Point pos)
{
    button->is_pressed = false;
}

void buttonMouseMove(Button *button, const Point pos)
{
    if (pointInRect(&pos, &button->rect)) {
        button->is_hovered = true;
    }
    else {
        button->is_hovered = false;
    }
}
