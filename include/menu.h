#ifndef MENU_H_INCLUDED_
#define MENU_H_INCLUDED_


#include <stdint.h>

#include "button.h"
#include "point.h"


typedef struct menu {
    uint8_t buttons_count;
    Button *buttons;
} Menu;


void initMainMenu(void);

void addButton(
    Menu *menu, const char *text,
    const Point position, const Size size
);

void menuClear(Menu *menu);


void menuMouseLeftDown(Menu *menu, const Point pos);

void menuMouseLeftUp(Menu *menu, const Point pos);

void menuMouseMove(Menu *menu, const Point pos);


#endif  /* MENU_H_INCLUDED_ */
