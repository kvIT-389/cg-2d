#include "rect.h"
#include "point.h"
#include "size.h"


Rect getRect(Point position, Size size)
{
    return (Rect){
        position.x, position.y,
        position.x, position.y + size.height,
        position.x + size.width, position.y + size.height,
        position.x + size.width, position.y
    };
}
