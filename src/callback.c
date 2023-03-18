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

void reshape(_size_t width, _size_t height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void mouse(
    _mouse_button_t button,
    _mouse_button_state_t state,
    _coord_t x, _coord_t y
)
{
    /* Code of mouse callback */
}

void keyboard(_key_t key, _coord_t x, _coord_t y)
{
    switch (key) {
        case '-':
            scale -= 0.05;
            if (scale < 0.0) {
                scale = 0.0;
            }

            break;

        case '+':
            scale += 0.05;
            if (scale > 1.0) {
                scale = 1.0;
            }

            break;

        case 'q':
            glutDestroyWindow(glutGetWindow());
            break;
    }
}

void specialKeyboard(
    _special_key_t key,
    _coord_t x, _coord_t y
)
{
    /* Code of special keyboard callback */
}
