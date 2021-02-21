//
// Created by viktor on 2021-02-01.
//

#ifndef GAMEENGINE_SHADERPROGRAMBASE_H
#define GAMEENGINE_SHADERPROGRAMBASE_H


#include <string>
#include "../Objects/GLMesh/GLMeshBase.h"
#include "../Objects/Materials/Material.h"
#include "ShaderVariableList.h"
#include <glm/gtc/type_ptr.hpp>

class ShaderProgramBase {
    std::string source;
    int vertexShader;
    int fragmentShader;
protected:
    unsigned int shaderID = glCreateProgram();
    ShaderVariableList var;
public:
    explicit ShaderProgramBase(std::string shaderSource);

    void use();

    void createVertexShader();

    void testShaderCompilation(unsigned int shader);

    void createFragmentShader();


//    void draw(GLMeshBase* object, Material material);

    virtual void setSpecifics() = 0;

    //void draw(std::shared_ptr<GLMeshBase> object);
    void draw(std::shared_ptr<GLMeshBase> object, Material material);

    int transformLoc;
    glm::mat4 trans = glm::mat4(1.0f);

    void setVector(unsigned int position, const float *valuePointer);
};


#endif //GAMEENGINE_SHADERPROGRAMBASE_H
