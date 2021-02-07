#include <iostream>
#include "Objects/Importer.h"
#include "WindowHandling/GLwindow.h"
#include "Shading/ShaderLoader.h"
#include "Shading/ShaderProgramBase.h"
#include "Shading/TexturePhongShader.h"


GLuint textureId;

int width;

int height;

int nrOfChannels;

int I = 0;

GLwindow w = GLwindow();
TexturePhongShader shader = TexturePhongShader("/home/viktor/CLionProjects/GameEngine/Shading/Shaders/phongSunTexture");

void testDraw(){
}

void testSetup(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);


//    unsigned char* data = stbi_load("/home/viktor/CLionProjects/GameEngine/Textures/Gravel/gravel_ground_01_diff_1k.jpg", &width, &height,&nrOfChannels, 0);
    glGenTextures(1, &textureId);
    std::cout << textureId;
    glBindTexture(GL_TEXTURE_2D, textureId);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
//    stbi_image_free((void *) data);
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

//    testSetup();
    GLMeshTexture object = Importer("../sphere2.obj").getMesh();
    object.setupMesh();
    std::shared_ptr<GLMeshBase> objPoint = std::make_unique<GLMeshTexture>(object);
    while(1){
        shader.draw(objPoint);
        w.updateWindow();
    }
    return 0;
}
