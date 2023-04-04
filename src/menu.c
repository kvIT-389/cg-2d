#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "rect.h"
#include "button.h"


Menu main_menu;


void initMainMenu(void)
{
    menuAddButton(&main_menu, "Button #1", (Point){10, 10}, (Size){80, 30});
    menuAddButton(&main_menu, "Button #2", (Point){10, 50}, (Size){80, 30});
    menuAddButton(&main_menu, "Button #3", (Point){10, 90}, (Size){80, 30});
}

void menuAddButton(
    Menu *menu, const char *text,
    Point position, Size size
)
{
    ++menu->buttons_count;
    menu->buttons = realloc(
        menu->buttons,
        menu->buttons_count * sizeof(Button)
    );

    Button *button = menu->buttons + (menu->buttons_count - 1);

    button->text = calloc(strlen(text), sizeof(char));
    strcpy(button->text, text);

    button->rect = getRect(position, size);

    button->is_hovered = false;
    button->is_pressed = false;
}

void menuClear(Menu *menu)
{
    while (menu->buttons_count > 0) {
        free(menu->buttons[--menu->buttons_count].text);
    }

    free(menu->buttons);
}


void menuMouseLeftDown(Menu *menu, Point position)
{
    for (int i = 0; i < menu->buttons_count; ++i) {
        buttonMouseLeftDown(menu->buttons + i, position);
    }
}

void menuMouseLeftUp(Menu *menu, Point position)
{
    for (int i = 0; i < menu->buttons_count; ++i) {
        buttonMouseLeftUp(menu->buttons + i, position);
    }
}

void menuMouseMove(Menu *menu, Point position)
{
    for (int i = 0; i < menu->buttons_count; ++i) {
        buttonMouseMove(menu->buttons + i, position);
    }
}
