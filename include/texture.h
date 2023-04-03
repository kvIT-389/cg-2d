#ifndef TEXTURE_H_INCLUDED_
#define TEXTURE_H_INCLUDED_


#include "types.h"
#include "size.h"


typedef struct texture
{
    _id_t id;
    Size size;
} Texture;


extern Texture test_texture;


void loadTexture(
    Texture *texture,
    const char *file_name
);


#endif  /* TEXTURE_H_INCLUDED_ */
