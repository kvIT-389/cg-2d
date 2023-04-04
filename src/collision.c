#include "collision.h"
#include "point.h"
#include "rect.h"


bool pointInRect(Point point, Rect rect)
{
    return (rect.vertices[0].x <= point.x) &&
           (rect.vertices[0].y <= point.y) &&
           (point.x <= rect.vertices[2].x) &&
           (point.y <= rect.vertices[2].y);
}
