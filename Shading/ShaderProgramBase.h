//
// Created by viktor on 2021-02-01.
//

#ifndef GAMEENGINE_SHADERPROGRAMBASE_H
#define GAMEENGINE_SHADERPROGRAMBASE_H


#include <string>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>

class ShaderProgramBase {
    std::string source;
    int vertexShader;
    int fragmentShader;
    void testProgramLinked();
    void createShader(int& shaderReference, unsigned int type);
    void testShaderCompilation(unsigned int shader);
    const char *getSourceCode(unsigned int type);
    void handleCompilationError(unsigned int shader, char *errorLog) const;
    void handleLinkingError() const;
protected:
    unsigned int shaderID = glCreateProgram();
    virtual unsigned int getUniform(const char* name);
public:
    explicit ShaderProgramBase(std::string shaderSource);
    ~ShaderProgramBase();
    void use();
};


#endif //GAMEENGINE_SHADERPROGRAMBASE_H
