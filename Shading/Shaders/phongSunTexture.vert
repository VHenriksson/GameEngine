#version 330 core
layout (location = 0) in vec3 inVertex;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec2 inTexture;
layout (location = 3) in vec3 inTangent;
layout (location = 4) in vec3 inBitangent;

out vec3 FragmentPosition;
out vec2 TextureCoordinate;
out vec3 TangentLightPosition;
out vec3 TangentViewPosition;
out vec3 TangentFragmentPosition;

uniform vec3 sunPos;
uniform mat4 transform;

void main()
{
    FragmentPosition = vec3(transform*vec4(vec3(inVertex),1));
   // Normal = mat3(transpose(inverse(transform))) * inNormal;
    //    gl_Position = transform * vec4( inVertex, 1 );
    mat3 normalMatrix = transpose(inverse(mat3(transform)));
    normalMatrix = mat3(1,0,0,0,1,0,0,0,-1) * normalMatrix;
    gl_Position = transform*vec4( inVertex, 1 );
    TextureCoordinate = inTexture;

    vec3 normal = normalize(normalMatrix*inNormal);
    vec3 tangent = -normalize(normalMatrix*inTangent);
    vec3 biTangent = cross(normal,tangent);//-normalize(normalMatrix*inBitangent);

    mat3 toTangentSpaceTransformation = inverse(mat3(tangent,biTangent,normal));
    TangentFragmentPosition = toTangentSpaceTransformation * FragmentPosition;
    TangentLightPosition = toTangentSpaceTransformation * sunPos;

    //toTangentSpaceTransformation * vec3(0,0,1);
    TangentViewPosition = toTangentSpaceTransformation * vec3(0,0,1);
}