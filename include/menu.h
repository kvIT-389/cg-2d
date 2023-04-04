#ifndef MENU_H_INCLUDED_
#define MENU_H_INCLUDED_


#include <stdint.h>

#include "button.h"
#include "point.h"
#include "size.h"


/**
 * Structure which stores set of buttons related to each other.
 */
typedef struct menu {
    uint8_t buttons_count;
    Button *buttons;
} Menu;


/**
 * Fills @a main_menu menu with buttons.
 */
void initMainMenu(void);


/**
 * Creates new button from the given @a text, @a position
 * and @a size and adds it to the given @a menu.
 */
void menuAddButton(
    Menu *menu, const char *text,
    Point position, Size size
);

/**
 * Clears given @a menu from all its buttons.
 */
void menuClear(Menu *menu);


/**
 * Function which is called after mouse left button press
 * at the given @a position and handles it for the given @a menu.
 */
void menuMouseLeftDown(Menu *menu, Point position);

/**
 * Function which is called after mouse left button release
 * at the given @a position and handles it for the given @a menu.
 */
void menuMouseLeftUp(Menu *menu, Point position);

/**
 * Function which is called after mouse move
 * to the given @a position and handles it for the given @a menu.
 */
void menuMouseMove(Menu *menu, Point position);


#endif  /* MENU_H_INCLUDED_ */
