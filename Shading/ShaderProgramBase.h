//
// Created by viktor on 2021-02-01.
//

#ifndef GAMEENGINE_SHADERPROGRAMBASE_H
#define GAMEENGINE_SHADERPROGRAMBASE_H


#include <string>
#include "../Objects/GLMesh/GLMeshBase.h"

class ShaderProgramBase {
    std::string source;
    int vertexShader;
    int fragmentShader;
protected:
    unsigned int shaderID = glCreateProgram();
public:
    explicit ShaderProgramBase(std::string shaderSource);

    void createVertexShader();

    void testShaderCompilation(unsigned int shader);

    void createFragmentShader();

    void draw(std::shared_ptr<GLMeshBase> object);

    virtual void setSpecifics() = 0;
};


#endif //GAMEENGINE_SHADERPROGRAMBASE_H
