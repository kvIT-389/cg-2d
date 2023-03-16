#include <GL/gl.h>
#include <GL/glut.h>


const unsigned int update_delay = 10;


float angle = 0.0;

void drawHexagon()
{
    glPushMatrix();

    glRotatef(angle, 0.0, 0.0, 1.0);

    glBegin(GL_POLYGON);
        glColor3ub(0xff, 0x00, 0x00);  glVertex2f( 1.0f,  0.0f);
        glColor3ub(0x7f, 0x7f, 0x00);  glVertex2f( 0.5f,  0.87f);
        glColor3ub(0x00, 0xff, 0x00);  glVertex2f(-0.5f,  0.87f);
        glColor3ub(0x00, 0x7f, 0x7f);  glVertex2f(-1.0f,  0.0f);
        glColor3ub(0x00, 0x00, 0xff);  glVertex2f(-0.5f, -0.87f);
        glColor3ub(0x7f, 0x00, 0x7f);  glVertex2f( 0.5f, -0.87f);
    glEnd();

    glPopMatrix();
}

void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    drawHexagon();

    glutSwapBuffers();
}

void update(int value)
{
    angle = (int)(angle + 1.0f) % 360;

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
