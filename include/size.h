#ifndef SIZE_H_INCLUDED_
#define SIZE_H_INCLUDED_


#include "types.h"


/**
 * Structure which stores values of rectangle size
 * i.e. width and height.
 * 
 * Each size component is stored in terms of window pixels.
 */
typedef struct size
{
    _size_t width, height;
} Size;


#endif  /* SIZE_H_INCLUDED_ */
