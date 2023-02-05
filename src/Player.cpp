#include "Player.hpp"
#include "WindowManager.hpp"
#include "WorldConstants.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h> 
#include <iostream>
#include <math.h>  



Player::Player()
{
    WindowManager &windowManager = WindowManager::Instance();
	window_ = windowManager.GetWindow();
}



void Player::ProcessInput(glm::vec3 playerPosition, glm::vec3 playerOrientation)
{
    // Get elapsed time so we can cap input at x times per second
    static GLdouble previous_seconds = glfwGetTime();
    GLdouble current_seconds = glfwGetTime();
    GLdouble elapsed_seconds = current_seconds - previous_seconds;

    // If you press escape on our window, close the window
    if (glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window_, true);
    }
    // Press 1 for wireframe
    if (glfwGetKey(window_, GLFW_KEY_1) == GLFW_PRESS)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    // Press 2 for filled
    if (glfwGetKey(window_, GLFW_KEY_2) == GLFW_PRESS)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    // Press f for fullscreen
    if (glfwGetKey(window_, GLFW_KEY_F) == GLFW_PRESS)
    {
        glfwMaximizeWindow(window_);
        glfwPollEvents();
    }

}


