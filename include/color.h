#ifndef COLOR_H_INCLUDED_
#define COLOR_H_INCLUDED_


#include "types.h"


/**
 * RGBA color structure.
 */
typedef struct color
{
    _rgba_channel_t r;
    _rgba_channel_t g;
    _rgba_channel_t b;
    _rgba_channel_t a;
} Color;


/**
 * Sets current OpenGL color.
 */
void setColor(const Color *color);


#endif  /* COLOR_H_INCLUDED_ */
