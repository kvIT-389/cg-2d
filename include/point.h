#ifndef POINT_H_INCLUDED_
#define POINT_H_INCLUDED_


#include "types.h"


/**
 * 2-dimensional point structure.
 * z-coordinate supposed to be 0.
 */
typedef struct point
{
    _coord_t x;
    _coord_t y;
} Point;


#endif  /* POINT_H_INCLUDED_ */
