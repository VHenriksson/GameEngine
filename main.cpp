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

int main() {
    std::cout << "Hello, World!" << std::endl;

    Importer i = Importer("../sphere2.obj");
    TextureList materials = i.getTextures();
    std::vector<GLMeshTexture> object = i.getMeshes();
    for(int i = 0; i < object.size(); i++){
        object[i].setupMesh();
    }
    std::cout << object.size() << std::endl;
    while(1){
        shader.draw(&object[0]);
        w.updateWindow();
    }
    return 0;
}
