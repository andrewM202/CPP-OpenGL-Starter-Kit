#version 430 core
out vec4 FragColor;

// Get our texture coordinate mappings
in vec2 TexCoord;
// Texture ID (block type)
in float TexID;

// Get the texture unit from when we bound our texture
uniform sampler2D ourTexture[1];	

void main()
{
    // Create texture
	vec4 Texture = texture(ourTexture[int(TexID)], TexCoord);

    // Render final output
    FragColor = Texture;// * vec4(1.0f, 0.5f, 0.2f, 1.0f);
} 