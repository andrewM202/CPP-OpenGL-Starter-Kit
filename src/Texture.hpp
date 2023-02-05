#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>



class Texture
{
public:
    GLuint textureID;
    GLint width, height, nrChannels;

    Texture(const char *filePath);
    Texture(){};

    void Bind();
    void Unbind();
    void Delete();
};