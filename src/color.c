#include <GL/gl.h>

#include "color.h"


void setColor(const Color *color)
{
    glColor4ub(color->r, color->g, color->b, color->a);
}
