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


struct material {

};

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
};

class GLMeshBase {
public:
    void initialize();
    void setupMesh();
    void print();
    void bind();
    void draw();
private:
    glContainer glData;
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
    std::vector<material> materials;
    virtual void setMaterial() = 0;

    virtual void prepareForDraw() = 0;
};


#endif //GAMEENGINE_GLMESHBASE_H
