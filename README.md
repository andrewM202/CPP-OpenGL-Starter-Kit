This example uses openGL [4.3](https://www.khronos.org/opengl/wiki/History_of_OpenGL#OpenGL_4.3_(2012)) for access to compute shaders. To use a lower version like 3.3 simply download a lower version of GLAD in the 1. setup

This project starts out with a basic vertex and fragment shader, and the necessary helper files. It starts out by drawing a small grid of textured cubes to the screen

### Source files
- Main.cpp : The entrypoint for the app, and where the OpenGL event loop is ran and classes are initialized
- Camera.hpp : Can be setup to handle model, view, projection matrices
- EBO.hpp : Helper class to generate Index buffer objects
- VBO.hpp : Helper class to generate Vertex buffer objects
- VAO.hpp : Helper class to generate Vertex array objects
- Texture.hpp : Easily generate a texture to use provided a path to an image file
- WindowManager.hpp : Create the window along with helper methods, like printing the FPS
- World.hpp : Initialize all the necessary buffers here and run our world logic
- ShaderManager.hpp : Takes a path to vertex and fragment shader files and initializes them
- Player.hpp : Creates a basic player class with input controls
- WorldConstants.hpp : Stores world variables, like the color of the sky to be used in any other file

### To Run App
1. cd bin
2. mingw32-make
3. .\main.exe


#### Setup the project on windows using:
1. [How to install OpenGL for C++ (Windows)](https://www.youtube.com/watch?v=hRInLNR9iRg)
2. [https://www.youtube.com/watch?v=oQHdm6TpLsU](https://www.youtube.com/watch?v=oQHdm6TpLsU)

