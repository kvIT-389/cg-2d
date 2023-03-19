#include <GL/glut.h>

#include "mainwindow.h"
#include "callback.h"
#include "update.h"


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

    initWindow(
        &main_window,
        "Rotating Hexagon",
        480, 480,
        200, 200
    );

    initCallbacks();
    runUpdateLoop();

    glutMainLoop();

    return 0;
}
