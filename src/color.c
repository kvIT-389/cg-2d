#include <GL/gl.h>

#include "color.h"


void setColor(const Color *color)
{
    glColor3ub(color->r, color->g, color->b);
}
