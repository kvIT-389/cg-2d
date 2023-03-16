#include <GL/glut.h>

#include "update.h"
#include "display.h"


const uint32_t update_delay = 10;


void update(int value)
{
    angle = (int)(angle + 1.0f) % 360;

    glutPostRedisplay();
    glutTimerFunc(update_delay, update, value);
}

void runUpdateLoop(void)
{
    glutTimerFunc(update_delay, update, 0);
}
