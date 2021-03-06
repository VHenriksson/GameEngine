//
// Created by viktor on 2021-01-20.
//

#ifndef GAMEENGINE_GLMESHBASE_H
#define GAMEENGINE_GLMESHBASE_H

#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <memory>
#include <glm/gtc/matrix_transform.hpp>
#include "../../Shading/ShaderProgramBase.h"

struct glContainer {
    unsigned int vao, vbo, ebo;
    void setup(){
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);
    };
    void bindEBO(){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    };
    void bindVAO(){
        glBindVertexArray(vao);
    };
    void bindVBO(){
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
    };
    void remove(){
        glDeleteBuffers(1,&vbo);
        glDeleteBuffers(1,&ebo);
        glDeleteVertexArrays(1,&vao);
    }
};

class GLMeshBase {
public:
    void initialize();
    void setupMesh();
    void draw();
    void setShader(std::shared_ptr<ShaderProgramBase> shader);
    virtual void drawSetup() = 0;
    std::shared_ptr<ShaderProgramBase> shader;
    ~GLMeshBase();
private:
    glContainer glData;
    glm::mat4 position = glm::mat4(1.0f);
    void makeVertices();
    void makeFaces();
    void pushVertexData();
    void setVertexPositions();
    void setVertexNormals();
protected:
    virtual unsigned int vertexSize() = 0;
    virtual unsigned int normalOffset() = 0;
    std::vector<float> vertices;
    std::vector<unsigned int> faceIndices;
    virtual void setSpecifics() = 0;
};


#endif //GAMEENGINE_GLMESHBASE_H
