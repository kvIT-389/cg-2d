#ifndef COLLISION_H_INCLUDED_
#define COLLISION_H_INCLUDED_


#include <stdbool.h>

#include "point.h"
#include "rect.h"


/**
 * Returns @c true if the given point is inside the given rectangle,
 * otherwise returns @c false.
 */
bool pointInRect(Point point, Rect rect);


#endif  /* COLLISION_H_INCLUDED_ */
