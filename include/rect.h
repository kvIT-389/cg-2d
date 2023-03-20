#ifndef RECT_H_INCLUDED_
#define RECT_H_INCLUDED_


#include "types.h"
#include "point.h"
#include "size.h"


/**
 * Rectangle on XY plane defined by its vertex
 * with minimal x and y coordinates, and its width and height.
 */
typedef struct rect
{
    _coord_t x;
    _coord_t y;

    _size_t width;
    _size_t height;
} Rect;


/**
 * Returns new Rect variable from its position and size.
 */
Rect getRect(const Point *pos, const Size *size);


/**
 * Returns position of the given rectangle as Point variable.
 */
Point getRectPosition(const Rect *rect);

/**
 * Returns size of the given rectangle as Size variable.
 */
Size getRectSize(const Rect *rect);


#endif  /* RECT_H_INCLUDED_ */
