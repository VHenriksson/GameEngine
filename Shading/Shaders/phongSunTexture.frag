#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragmentPosition;
in vec2 TextureCoordinate;
uniform vec3 sunPos;

uniform sampler2D Texture;

void main() {
    float shininess = 3;
    vec3 phongVector = vec3(0.6,0.7,0.5);
//    vec4 color = vec4(1,TextureCoordinate,1);
    vec4 color = texture(Texture,TextureCoordinate);
    vec4 ambientLightColor = vec4(0.2,0.2,0.2,0.2);


    vec4 sunLightColor = vec4(1,1,1,1);
    vec3 sunLightDirection = normalize(vec3(2,2,0));
    vec4 ambientLight = phongVector[0] * ambientLightColor;

    // Calculation of diffuse light
    vec3 norm = normalize(Normal);
    float diffuseConst = max(dot(norm,sunLightDirection),0.0);
    vec4 diffuseLight = phongVector[1] * diffuseConst * sunLightColor;

    // Calculation of specular light
    vec3 viewDirection = normalize(vec3(0,0,1) - FragmentPosition);
    vec3 reflectionDirection = reflect(sunLightDirection,norm);
    float spec = pow(max(dot(viewDirection,reflectionDirection),0),shininess);
    vec4 specularLight = phongVector[2] * spec * sunLightColor;

    vec4 phongColor = (ambientLight  + specularLight) * color;

    FragColor = phongColor;
}
