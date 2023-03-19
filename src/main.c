#include <GL/glut.h>

#include "mainwindow.h"
#include "callback.h"
#include "update.h"


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

    Size size = {480, 480};
    Point position = {200, 200};
    initWindow(
        &main_window, "Rotating Hexagon", size, position
    );

    initCallbacks();
    runUpdateLoop();

    glutMainLoop();

    return 0;
}
