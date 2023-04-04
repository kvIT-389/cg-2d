#ifndef RECT_H_INCLUDED_
#define RECT_H_INCLUDED_


#include "types.h"
#include "point.h"
#include "size.h"


/**
 * Structure to store rectangle vertices
 * as array of @a Point instances.
 */
typedef struct rect
{
    Point vertices[4];
} Rect;


/**
 * Returns new Rect instance from its @a position and @a size.
 */
Rect getRect(Point position, Size size);


#endif  /* RECT_H_INCLUDED_ */
