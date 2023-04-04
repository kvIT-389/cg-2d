#include <stdio.h>

#include "button.h"

#include "color.h"
#include "collision.h"


const Color default_color = {0xe0, 0xe0, 0xe0, 0xff};
const Color hovered_color = {0xd0, 0xd0, 0xd0, 0xff};
const Color pressed_color = {0xb0, 0xb0, 0xb0, 0xff};
const Color border_color  = {0x70, 0x70, 0x70, 0xff};


void buttonMouseLeftDown(Button *button, Point position)
{
    if (pointInRect(position, button->rect)) {
        button->is_pressed = true;
        printf("%s pressed.\n", button->text);
    }
}

void buttonMouseLeftUp(Button *button, Point position)
{
    button->is_pressed = false;
}

void buttonMouseMove(Button *button, Point position)
{
    if (pointInRect(position, button->rect)) {
        button->is_hovered = true;
    }
    else {
        button->is_hovered = false;
    }
}
