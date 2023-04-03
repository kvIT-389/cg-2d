#include <GL/glut.h>

#include "mainwindow.h"
#include "mainmenu.h"
#include "callback.h"
#include "update.h"
#include "texture.h"


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);

    initWindow(
        &main_window, "Rotating Hexagon",
        getSize(480, 480),
        getPoint(200, 200)
    );

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);
    loadTexture(&test_texture, "img/0.png");

    initMainMenu();

    initCallbacks();
    runUpdateLoop();

    glutMainLoop();

    return 0;
}
