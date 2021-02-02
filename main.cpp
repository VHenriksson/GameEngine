#include <iostream>
#include "Objects/Importer.h"
#include "WindowHandling/GLwindow.h"
#include "Shading/ShaderLoader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "Textures/stb_image.h"
#include "Shading/ShaderProgram.h"


GLuint textureId;

int width;

int height;

int nrOfChannels;

int I = 0;

GLwindow w = GLwindow();
ShaderProgram shader = ShaderProgram("/home/viktor/CLionProjects/GameEngine/Shading/Shaders/phongSunTexture");

void testDraw(){
    shader.draw();
}

void testSetup(){

    Importer i = Importer("../monkeyBoy.obj");
    Importer j = Importer("../cube2.obj");

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    unsigned char* data = stbi_load("/home/viktor/CLionProjects/GameEngine/Textures/Gravel/gravel_ground_01_diff_1k.jpg", &width, &height,&nrOfChannels, 0);
    glGenTextures(1, &textureId);
    std::cout << textureId;
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free((void *) data);

    /*
    GLint vShaderCompiled = GL_TRUE;
    char errorLog[512];
    glGetShaderiv(shaderProgram, GL_COMPILE_STATUS, &vShaderCompiled );
    if( vShaderCompiled != GL_TRUE )
    {
        glGetShaderInfoLog(shaderProgram, 512, nullptr, &errorLog[0]);
        glDeleteShader(shaderProgram); // Don't leak the shader
        throw std::runtime_error( "Unable to compile shader! Shader ID: " + std::to_string(shaderProgram) + ". Shaderlog:\n" + errorLog);
    }
*/
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    testSetup();
    while(1){
        testDraw();
        w.updateWindow();
    }
    return 0;
}
