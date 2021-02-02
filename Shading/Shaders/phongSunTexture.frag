#version 330 core
out vec4 FragColor;

//in vec3 Normal;
//in vec3 FragmentPosition;
in vec2 TextureCoordinate;

uniform sampler2D Texture;

void main() {
    FragColor = texture(Texture,TextureCoordinate);
}
