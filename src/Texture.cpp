#include "Texture.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h> // Used for textures / image processing
#include <iostream>



Texture::Texture(const char *filePath)
{
    // Generate a texture reference ID
    glGenTextures(1, &textureID);
    // Bind our texture to the GL_TEXTURE_2D target
    glBindTexture(GL_TEXTURE_2D, textureID);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load and generate the texture
    unsigned char *data = stbi_load(filePath, &width, &height, &nrChannels, STBI_rgb_alpha); // Loading as rgb_alpha so transparent pixels are transparent
    // Flip textures on load
    stbi_set_flip_vertically_on_load(true);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data); // GL_RGBA instead of GL_RGB so transparent pixels load correctly
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
}



void Texture::Bind()
{
    // Bind our texture to the GL_TEXTURE_2D target
    glBindTexture(GL_TEXTURE_2D, textureID);
}



void Texture::Unbind()
{
    // Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);
}
    


void Texture::Delete()
{
    glDeleteTextures(1, &textureID);
}
