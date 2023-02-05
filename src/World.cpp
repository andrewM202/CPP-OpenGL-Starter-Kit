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
    TileVAO.LinkAttrib(TileVBO, 0, 3, GL_FLOAT, 3 * sizeof(GLfloat), (void*)0);

    // Unbind all to prevent accidentally modifying them
	TileVAO.Unbind();
	TileVBO.Unbind();
	TileEBO.Unbind();
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


