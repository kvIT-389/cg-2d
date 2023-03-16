#include <GL/gl.h>
#include <GL/glut.h>

#include "display.h"
#include "update.h"


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(480, 480);
    glutInitWindowPosition(200, 200);

    glutCreateWindow("Rotating hexagon");

    glutDisplayFunc(display);

    runUpdateLoop();

    glutMainLoop();

    return 0;
}
