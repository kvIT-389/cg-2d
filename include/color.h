#ifndef COLOR_H_INCLUDED_
#define COLOR_H_INCLUDED_


#include "types.h"


/**
 * Structure which stores RGBA color as array of 4
 * its components i.e. red, green, blue and alpha channels.
 */
typedef struct color
{
    _rgba_channel_t channels[4];
} Color;


/* Predefined colors */

extern const Color white;


/**
 * Sets current OpenGL color to @a color.
 */
void setCurrentColor(const Color *color);


#endif  /* COLOR_H_INCLUDED_ */
