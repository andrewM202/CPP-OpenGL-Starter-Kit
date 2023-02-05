#include "World.hpp"
#include "resources/Models/tile.cpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> // For glm::value_ptr

// Constructor
World::World() : tileShaderProgram("../src/shaders/tile.vert", "../src/shaders/tile.frag")
{
    TileVAO.Bind();
    // Generates Vertex Buffer Object and links it to vertices
    TileVBO.InitVBO(tileVertices, sizeof(tileVertices));
	// Generates Element Buffer Object and links it to indices
	TileEBO.InitEBO(tileIndices, sizeof(tileIndices));

    // Links VBO attributes such as coordinates and colors to VAO
    TileVAO.LinkAttrib(TileVBO, 0, 3, GL_FLOAT, 5 * sizeof(GLfloat), (void*)0);
    TileVAO.LinkAttrib(TileVBO, 1, 2, GL_FLOAT, 5 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

    // Unbind all to prevent accidentally modifying them
	TileVAO.Unbind();
	TileVBO.Unbind();
	TileEBO.Unbind();

    // Activate all of our textures
    ActivateTextures();
}



// Destructor
World::~World()
{
    TileVAO.Delete();
    TileVBO.Delete();
    TileEBO.Delete();
}



// Run the event loop once
void World::RunLoop(GLFWwindow *window)
{
    // Tells OpenGL which Shader Program we want to use
    tileShaderProgram.Activate();
    // Bind the VAO so OpenGL knows to use it
    TileVAO.Bind();

    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  -24.0f), 
        glm::vec3( 2.0f,  5.0f, -24.0f), 
        glm::vec3(-1.5f, -2.2f, -2.5f),  
        glm::vec3(-3.8f, -2.0f, -12.3f),  
        glm::vec3( 2.4f, -0.4f, -3.5f),  
        glm::vec3(-1.7f,  3.0f, -7.5f),  
        glm::vec3( 1.3f, -2.0f, -2.5f),  
        glm::vec3( 1.5f,  2.0f, -2.5f), 
        glm::vec3( 1.5f,  0.2f, -1.5f), 
        glm::vec3(-1.3f,  1.0f, -1.5f)  
    };
    glm::mat4 model = glm::mat4(1.0f);
    // model = glm::rotate(model, glm::radians(0.f), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::translate(model, glm::vec3(1.0f, 1.0f, -24.0f)); // Position of the block in xy. Z is how small/big the block is. I.e. z == 24 means block is 512 pixels / 24 big 

    glm::mat4 view = glm::mat4(1.0f);
    // note that we're translating the scene in the reverse direction of where we want to move
    view = glm::translate(view, glm::vec3(1.0f, 1.0f, 1.0f));  // Z is how zoomed in on the blocks we are. > 1 is more zoomed in, < 0 is less zoomed in

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 1350.0f / 850.0f, 0.1f, 100.0f);

    glUniformMatrix4fv(glGetUniformLocation(tileShaderProgram.GetID(), "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    glUniformMatrix4fv(glGetUniformLocation(tileShaderProgram.GetID(), "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(tileShaderProgram.GetID(), "model"), 1, GL_FALSE, glm::value_ptr(model));

    for(int i = -10; i < 10; i++)
    {
        model= glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(1.0f * (GLfloat)i, 1.0f, -24.0f)); 
        glUniformMatrix4fv(glGetUniformLocation(tileShaderProgram.GetID(), "model"), 1, GL_FALSE, glm::value_ptr(model));
        glDrawElements(GL_TRIANGLES, sizeof(tileIndices) / sizeof(GLint), GL_UNSIGNED_INT, 0);
        
    }
}



void World::ActivateTextures()
{
    // Tells OpenGL which Shader Program we want to use
    tileShaderProgram.Activate();

    // Activate our various textures (grass, dirt, etc)
    // and bind our TextureIDs to them
    glActiveTexture(GL_TEXTURE1); // Activate texture unit 1, index 0
    glBindTexture(GL_TEXTURE_2D, grassBlockTop.textureID);

    // Pass in the TextureID to the uniforms for all of our textures 
    // so they can be used in the fragment shader
    GLuint location = glGetUniformLocation(tileShaderProgram.GetID(), "ourTexture");
                    // 0, 1, 2. These indexes are determined by the order we call glActiveTexture
    GLint samplers[9] = {0};
    glUniform1iv(location, 1, samplers);
}


