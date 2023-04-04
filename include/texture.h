#ifndef TEXTURE_H_INCLUDED_
#define TEXTURE_H_INCLUDED_


#include "types.h"
#include "size.h"


/**
 * Structure which stores @a id of some texture
 * and its size in pixels.
 * 
 * if @a id is equals to zero texture is not associated
 * with any texture on GPU.
 */
typedef struct texture
{
    _texture_id_t id;

    Size size;
} Texture;


extern Texture test_texture;


/**
 * Loads texture from the file specified by @a file_name
 * and saves associated with it id and size to the @a texture.
 */
void loadTexture(
    Texture *texture, const char *file_name
);


#endif  /* TEXTURE_H_INCLUDED_ */
