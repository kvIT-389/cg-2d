#include <GL/gl.h>

#include "color.h"


const Color white = {0xff, 0xff, 0xff, 0xff};


void setCurrentColor(const Color *color)
{
    glColor4ubv(color->channels);
}
