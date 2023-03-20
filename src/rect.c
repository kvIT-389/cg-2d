#include "rect.h"
#include "point.h"
#include "size.h"


Rect getRect(const Point *pos, const Size *size)
{
    Rect rect = {pos->x, pos->y, size->width, size->height};

    return rect;
}


Point getRectPosition(const Rect *rect)
{
    return getPoint(rect->x, rect->y);
}

Size getRectSize(const Rect *rect)
{
    return getSize(rect->width, rect->height);
}
