#include "WindowManager.hpp"
#include "World.hpp"
#include "WorldConstants.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
 
int main() {
    // Initialize Classes
    WindowManager &window = WindowManager::Instance();
    World &world = World::Instance();

    // Render Loop
    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        glClearColor(WorldVars::skyColor.x, WorldVars::skyColor.y, WorldVars::skyColor.z, WorldVars::skyColor.w);
        // Error logging
        window.CheckErrors();
        // Set FPS and camera coordinates to GLFW window title
        window.SetWindowTitle("FPS: " + std::to_string(window.GetFPS()));

        // Test draw something
        world.RunLoop(window.GetWindow());

        // Last in while loop, clear the buffers and poll events, setting up window for next frame
        window.setupNextFrame();
    }

    return 0;
}