#version 430
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

// Output textures to the Fragment Shader
out vec2 TexCoord;
// Output texture ID to the Fragment Shader
out float TexID;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    TexCoord = aTexCoord;
    TexID = 0; // Id 0 is grass block top for now
}