#include <GL/gl.h>
#include <GL/glut.h>

#include "callback.h"
#include "draw.h"


void initCallbacks(void)
{
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMouseFunc(mouse);

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyboard);
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    draw();

    if (glutGet(GLUT_WINDOW_DOUBLEBUFFER)) {
        glutSwapBuffers();
    }
    else {
        glFlush();
    }
}

void reshape(_width_t w, _height_t h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void mouse(
    _mouse_button_t button,
    _mouse_button_state_t state,
    int32_t x, int32_t y
)
{
    /* Code of mouse callback */
}

void keyboard(_key_t key, int32_t x, int32_t y)
{
    switch (key) {
        case 'q':
            glutDestroyWindow(glutGetWindow());
            break;
    }
}

void specialKeyboard(
    _special_key_t key,
    int32_t x, int32_t y
)
{
    /* Code of special keyboard callback */
}
