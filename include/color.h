#ifndef COLOR_H_INCLUDED_
#define COLOR_H_INCLUDED_


#include "types.h"


/**
 * RBG color structure.
 */
typedef struct color
{
    _rgb_channel_t r;
    _rgb_channel_t g;
    _rgb_channel_t b;
} Color;


/**
 * Sets current OpenGL color.
 */
void setColor(const Color *color);


#endif  /* COLOR_H_INCLUDED_ */
