#pragma once

#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"
#include "ShaderManager.hpp"
#include "Texture.hpp"

#include <GLFW/glfw3.h>


class World
{
public:
    Shader tileShaderProgram{"../src/shaders/tile.vert", "../src/shaders/tile.frag"};

    VAO TileVAO;
    VBO TileVBO;
    EBO TileEBO;

    // Our textures
    Texture grassBlockTop{"../src/resources/textures/ground_top_512.png"};

    // Singleton Design
    static World &Instance()
    {
        static World instance;
        return instance;
    }

    // Constructor
    World();
    // Destructor
    ~World();

    // Run the event loop once
    void RunLoop(GLFWwindow *window);
    // Activate textures
    void ActivateTextures();
};


