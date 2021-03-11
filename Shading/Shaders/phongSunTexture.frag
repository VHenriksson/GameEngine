#version 330 core
out vec4 FragColor;

in vec3 FragmentPosition;
in vec2 TextureCoordinate;
in vec3 TangentLightPosition;
in vec3 TangentViewPosition;
in vec3 TangentFragmentPosition;

uniform vec3 phongVector;
uniform int shininess;

uniform sampler2D Texture;
uniform sampler2D normalTexture;


void main() {
    vec3 normal = texture(normalTexture, TextureCoordinate).rgb;
    normal = normalize(normal * 2.0 - 1.0);
    //vec3 normal = vec3(0,0,1);
//    vec3 phongVector = vec3(0.3,0.7,1);
    vec4 color = texture(Texture,TextureCoordinate);
    vec4 ambientLightColor = vec4(1,1,1,1);//vec4(normalOffset,1);

    // Calculation of ambient light
    vec4 sunLightColor = vec4(1,1,1,1);
    vec3 sunLightDirection = normalize(TangentLightPosition);
    vec4 ambientLight = phongVector[0] * ambientLightColor;

    // Calculation of diffuse light
    float diffuseConst = max(dot(normal,sunLightDirection),0.0);
    vec4 diffuseLight = phongVector[1] * diffuseConst * sunLightColor;

    // Calculation of specular light
    vec3 reflectionDirection = reflect(sunLightDirection,normal);
    vec3 viewDirection = normalize(TangentViewPosition - TangentFragmentPosition);
    float spec = pow(max(dot(reflectionDirection,viewDirection),0),shininess);
    vec4 specularLight = phongVector[2] * spec * sunLightColor;

    //FragColor = vec4(TangentViewPosition,1);
    //FragColor = vec4(TangentFragmentPosition,1);
    FragColor = (specularLight + diffuseLight + ambientLight) * color;
}
