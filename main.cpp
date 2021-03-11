#include <iostream>
#include "Objects/Importer.h"
#include "WindowHandling/GLwindow.h"
#include "Shading/ShaderLoader.h"
#include "Shading/ShaderProgramBase.h"
#include "Shading/TexturePhongShader.h"
#include "Scenes/GameScenes/TestScene.h"
#include "GameEngine.h"


GLuint textureId;

int width;

int height;

int nrOfChannels;

int I = 0;

//GLwindow w = GLwindow();

int main() {
    GameEngine();
/*    std::shared_ptr<Scene> s = std::make_shared<TestScene>(TestScene());
    s->load();
    while(1){
        s->draw();
        w.updateWindow();
    }
    */
//    Importer i = Importer("../spheres.obj");
//    TextureList materials = i.getTextures();
/*    std::vector<GLMeshTexture> object = i.getMeshes();
    for(int i = 0; i < object.size(); i++){
        object[i].setupMesh();
    }
    std::cout << object.size() << std::endl;

    glBindTexture(GL_TEXTURE_2D, 76);




    glEnable(GL_DEPTH_TEST);
    while(1){
        for(int i = 0; i < object.size(); i++){
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, 2*i+1);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, 2*i + 2);
            shader.draw(&object[i],materials.get(object[i].getMaterial()));
        }
        w.updateWindow();
    }*/
    return 0;
}
