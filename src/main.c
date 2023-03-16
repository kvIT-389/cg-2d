#include <GL/gl.h>
#include <GL/glut.h>

#include "display.h"


const unsigned int update_delay = 10;


void update(int value)
{
    angle = (int)(angle + 1.0) % 360;

    glutPostRedisplay();
    glutTimerFunc(update_delay, update, value);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(480, 480);
    glutInitWindowPosition(200, 200);

    glutCreateWindow("Rotating hexagon");

    glutDisplayFunc(display);
    glutTimerFunc(update_delay, update, 0);

    glutMainLoop();

    return 0;
}
