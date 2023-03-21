#include <GL/gl.h>
#include <GL/glut.h>

#include "callback.h"

#include "mainwindow.h"
#include "draw.h"
#include "mainmenu.h"


void initCallbacks(void)
{
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutPassiveMotionFunc(passiveMotion);

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
    main_window.size = getSize(width, height);

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
    Point pos = {x, y};

    switch (button) {
        case GLUT_LEFT_BUTTON:
            switch (state) {
                case GLUT_DOWN:
                    menuMouseLeftDown(&main_menu, pos);

                    break;

                case GLUT_UP:
                    menuMouseLeftUp(&main_menu, pos);

                    break;
            }

            break;
    }
}

void motion(_coord_t x, _coord_t y)
{
    /* Code of mouse motion callback */
}

void passiveMotion(_coord_t x, _coord_t y)
{
    Point pos = {x, y};

    menuMouseMove(&main_menu, pos);
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
            destroyWindow(&main_window);
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
