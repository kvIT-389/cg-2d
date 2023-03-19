#include <string.h>

#include <GL/glut.h>

#include "window.h"
#include "types.h"
#include "mainwindow.h"


Window main_window;


void initWindow(
    Window *window, const char *title,
    _size_t width, _size_t height,
    _coord_t x, _coord_t y
)
{
    if (window->id) return;

    glutInitWindowSize(width, height);
    glutInitWindowPosition(x, y);

    window->id = glutCreateWindow(title);

    window->width = width;
    window->height = height;

    strcpy(window->title, title);
}

void destroyWindow(Window *window)
{
    glutDestroyWindow(window->id);

    window->id = 0;
}
