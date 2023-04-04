#include <GL/gl.h>

#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"


Texture test_texture;


void loadTexture(
    Texture *texture, const char *file_name
)
{
    if (texture->id) return;  /* Error: texture is already loaded. */

    Size size;
    int channels_count;

    _rgba_channel_t *data = stbi_load(
        file_name, &size.width, &size.height, &channels_count, 0
    );

    texture->size = size;

    GLint color_format = (channels_count == 4) ? GL_RGBA : GL_RGB;

    glGenTextures(1, &texture->id);
    glBindTexture(GL_TEXTURE_2D, texture->id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, color_format, size.width, size.height,
                                    0, color_format, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(data);
}
