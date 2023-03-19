#ifndef WINDOW_H_INCLUDED_
#define WINDOW_H_INCLUDED_


#include "types.h"


/**
 * Structure to store data associated
 * with one of the application windows.
 */
typedef struct window
{
    _id_t id;

    char title[100];

    _size_t width;
    _size_t height;
} Window;


/**
 * Creates a new window and
 * initializes @a window structure with related to it data.
 */
void initWindow(
    Window *window, const char *title,
    _size_t width, _size_t height,
    _coord_t x, _coord_t y
);

/**
 * Destroys destroys the window specified by @a window
 * and associated with it OpenGL context.
 */
void destroyWindow(Window *window);


#endif  /* WINDOW_H_INCLUDED_ */
