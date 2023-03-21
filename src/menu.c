#include <stdlib.h>
#include <string.h>

#include "menu.h"


Menu main_menu;


void addButton(
    Menu *menu, const char *text,
    const Point position, const Size size
)
{
    ++menu->buttons_count;
    menu->buttons = realloc(
        menu->buttons,
        menu->buttons_count * sizeof(Button)
    );

    Button button;

    strcpy(button.text, text);
    button.rect = getRect(&position, &size);

    menu->buttons[menu->buttons_count - 1] = button;
}


void menuMouseLeftDown(Menu *menu, const Point pos)
{
    for (int i = 0; i < menu->buttons_count; ++i) {                        
        buttonMouseLeftDown(menu->buttons + i, pos);
    }
}

void menuMouseLeftUp(Menu *menu, const Point pos)
{
    for (int i = 0; i < menu->buttons_count; ++i) {                        
        buttonMouseLeftUp(menu->buttons + i, pos);
    }
}

void menuMouseMove(Menu *menu, const Point pos)
{
    for (int i = 0; i < menu->buttons_count; ++i) {                        
        buttonMouseMove(menu->buttons + i, pos);
    }
}
