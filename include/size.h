#ifndef SIZE_H_INCLUDED_
#define SIZE_H_INCLUDED_


#include "types.h"


/**
 * 2-dimensional size structure.
 */
typedef struct size
{
    _size_t width;
    _size_t height;
} Size;


/**
 * Returns new Size variable from the given width and height.
 */
Size getSize(_size_t width, _size_t height);


#endif  /* SIZE_H_INCLUDED_ */
