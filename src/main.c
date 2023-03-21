#include <GL/glut.h>

#include "mainwindow.h"
#include "mainmenu.h"
#include "callback.h"
#include "update.h"


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

    initWindow(
        &main_window, "Rotating Hexagon",
        getSize(480, 480),
        getPoint(200, 200)
    );

    addButton(&main_menu, "Button #1", getPoint(10, 10), getSize(80, 30));
    addButton(&main_menu, "Button #2", getPoint(10, 45), getSize(80, 30));
    addButton(&main_menu, "Button #3", getPoint(10, 80), getSize(80, 30));

    initCallbacks();
    runUpdateLoop();

    glutMainLoop();

    return 0;
}
