// The vertices for a square tile 

// GLfloat tileVertices[] =
// { //     COORDINATES     //
// 	-0.5f, -0.5f, 0.0f, // 0
// 	 0.5f,  0.5f, 0.0f, // 1
// 	 0.5f, -0.5f, 0.0f, // 2
// 	-0.5f,  0.5f, 0.0f, // 3
// };



GLfloat tileVertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};  

GLuint tileIndices[] = {
    0, 1, 2
};  



// GLuint lightIndices[] =
// {
// 	0, 1, 2, 1, 0, 3, // Back face
// 	4, 5, 6, 5, 4, 7, // Front face
// 	6, 0, 4, 0, 6, 3, // Left face
// 	5, 2, 1, 2, 5, 7, // Right face
// 	3, 5, 1, 5, 3, 6, // Top face
// 	4, 2, 7, 2, 4, 0, // Bottom face
// };