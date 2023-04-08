#include <GL/gl.h>

#include "texture.h"
#include "image.h"


Texture test_texture;


void textureLoad(Texture *texture, const char *file_name)
{
    if (texture->id) return;  /* Error: texture is already loaded. */

    Image image = {};
    imageLoad(&image, file_name);

    texture->size = image.size;

    GLint color_format;
    if (image.channels_count == 4) {
        color_format = GL_RGBA;
    }
    else {
        color_format = GL_RGB;
    }

    glGenTextures(1, &texture->id);

    glBindTexture(GL_TEXTURE_2D, texture->id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(
            GL_TEXTURE_2D, 0, color_format,
            image.size.width, image.size.height,
            0, color_format, GL_UNSIGNED_BYTE, image.data
        );
    glBindTexture(GL_TEXTURE_2D, 0);

    imageFree(&image);
}

void textureFree(Texture *texture)
{
    if (!texture->id) return;  /* Error: texture is not loaded. */

    glDeleteTextures(1, &texture->id);

    *texture = (Texture){};
}
