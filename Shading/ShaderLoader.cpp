//
// Created by viktor on 2021-01-29.
//

#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>
#include "ShaderLoader.h"
const char* ShaderLoader::load(std::string source) {
    std::string shader;
    std::string fullSource = "../Shading/Shaders/" + source;
    std::fstream readFile(fullSource, std::ios::in);
    if (readFile.is_open()){
        std::stringstream buffer;
        buffer << readFile.rdbuf();
        shader = buffer.str();
    } else {
        throw std::runtime_error( "Couldn't load shader file: " + source);
    }
    std::cout << shader << std::endl;
    return shader.c_str();
}
