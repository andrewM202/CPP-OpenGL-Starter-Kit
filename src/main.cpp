#include "WindowManager.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "WorldConstants.hpp"
#include "Player.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
 
int main() {
    // Initialize Classes
    WindowManager &window = WindowManager::Instance();
    World &world = World::Instance();
    Camera camera(window.GetResolution().x, window.GetResolution().y, glm::vec3(0.0f, 0.0f, 0.0f)); // Camera width, camera height, camera starting position
    Player player;

    // Enable blending for transparent blocks
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Render Loop
    while (!glfwWindowShouldClose(window.GetWindow()))
    {
        glClearColor(WorldVars::skyColor.x, WorldVars::skyColor.y, WorldVars::skyColor.z, WorldVars::skyColor.w);
        // Error logging
        window.CheckErrors();
        // Set FPS and camera coordinates to GLFW window title
        window.SetWindowTitle("FPS: " + std::to_string(window.GetFPS()));

        // Process user input
        player.ProcessInput(camera.Position, camera.Orientation);

        // Test draw something
        world.RunLoop(window.GetWindow());

        // Last in while loop, clear the buffers and poll events, setting up window for next frame
        window.setupNextFrame();
    }

    return 0;
}