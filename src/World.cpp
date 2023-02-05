#include "World.hpp"
#include "resources/Models/tile.cpp"


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
    // Draw our tiles
    glDrawElements(GL_TRIANGLES, sizeof(tileIndices) / sizeof(GLint), GL_UNSIGNED_INT, 0);
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


