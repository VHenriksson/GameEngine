#version 330 core
layout (location = 0) in vec3 inVertex;
//layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inTexture;

//out vec3 FragmentPosition;
//out vec3 Normal;
out vec2 TextureCoordinate;

//uniform mat4 transform;

void main()
{
    //    FragmentPosition = vec3(inVertex);
    //    Normal = mat3(transpose(inverse(transform))) * inNormal;
    //    gl_Position = transform * vec4( inVertex, 1 );
    gl_Position = vec4( inVertex, 1 );
    TextureCoordinate = inTexture;
}