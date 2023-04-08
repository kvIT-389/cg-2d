#include <GL/glut.h>

#include "mainwindow.h"
#include "mainmenu.h"
#include "callback.h"
#include "update.h"
#include "texture.h"
#include "point.h"
#include "size.h"


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);

    initWindow(
        &main_window, "Rotating Hexagon",
        (Size){480, 480},
        (Point){200, 200}
    );

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_TEXTURE_2D);
    textureLoadFromFile(&test_texture, "img/0.png");

    initMainMenu();

    initCallbacks();
    runUpdateLoop();

    glutMainLoop();

    textureFree(&test_texture);

    return 0;
}
