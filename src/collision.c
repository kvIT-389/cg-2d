#include "collision.h"
#include "point.h"
#include "rect.h"


bool pointInRect(const Point *point, const Rect *rect)
{
    return (point->x >= rect->x) &&
           (point->y >= rect->y) &&
           (rect->x + rect->width >= point->x) &&
           (rect->y + rect->height >= point->y);
}
