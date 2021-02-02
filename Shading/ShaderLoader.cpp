//
// Created by viktor on 2021-01-29.
//

#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include "ShaderLoader.h"
std::string ShaderLoader::load(std::string source) {
    std::string shader;
    std::string fullSource = source;
    std::fstream readFile(fullSource, std::ios::in);
    if (readFile.is_open()){
        std::stringstream buffer;
        buffer << readFile.rdbuf();
        shader = buffer.str() + "\0";
    } else {
        throw std::runtime_error( "Couldn't load shader file: " + fullSource);
    }
    return shader;
}
