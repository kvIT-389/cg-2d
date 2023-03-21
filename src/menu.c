#include <stdlib.h>
#include <string.h>

#include "menu.h"


Menu main_menu;


void initMainMenu(void)
{
    addButton(&main_menu, "Button #1", getPoint(10, 10), getSize(80, 30));
    addButton(&main_menu, "Button #2", getPoint(10, 45), getSize(80, 30));
    addButton(&main_menu, "Button #3", getPoint(10, 80), getSize(80, 30));
}

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

void menuClear(Menu *menu)
{
    menu->buttons_count = 0;

    free(menu->buttons);
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
