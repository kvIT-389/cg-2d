#ifndef RECT_H_INCLUDED_
#define RECT_H_INCLUDED_


#include "point.h"
#include "size.h"


/**
 * Rectangle on XY plane defined by its vertex
 * with minimal x and y coordinates, and its size.
 * 
 * @c pos - rectangle vertex with minimal coordinates.
 * @c size - rectangle size.
 */
typedef struct rect
{
    Point pos;
    Size size;
} Rect;


#endif  /* RECT_H_INCLUDED_ */
