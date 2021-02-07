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

    Importer i = Importer("../spheres.obj");
    TextureList materials = i.getTextures();
    std::vector<GLMeshTexture> object = i.getMeshes();
    for(int i = 0; i < object.size(); i++){
        object[i].setupMesh();
    }
    std::cout << object.size() << std::endl;

    glBindTexture(GL_TEXTURE_2D, 76);
    while(1){
        glClearColor(0, 0, 0.1, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for(int i = 0; i < object.size(); i++){
            shader.draw(&object[i],materials.get(object[i].getMaterial()));
        }
        w.updateWindow();
    }
    return 0;
}
