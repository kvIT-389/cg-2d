#include <string.h>

#include <GL/glut.h>

#include "window.h"
#include "types.h"
#include "mainwindow.h"


Window main_window;


void initWindow(
    Window *window, const char *title,
    const Size size, const Point position
)
{
    if (window->id) return;

    glutInitWindowSize(size.width, size.height);
    glutInitWindowPosition(position.x, position.y);

    window->id = glutCreateWindow(title);
    window->size = size;

    strcpy(window->title, title);
}

void destroyWindow(Window *window)
{
    glutDestroyWindow(window->id);

    window->id = 0;
}
