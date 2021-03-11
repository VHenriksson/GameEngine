//
// Created by viktor on 2021-02-24.
//

#include "PhongShader.h"


void PhongShader::setPhongDetails(glm::vec3 phongVector, int shininess) {
    glUniform3fv(this->phongVector, 1, glm::value_ptr(phongVector));
    glUniform1i(this->shininess,shininess);
}

PhongShader::PhongShader(std::string source) : ShaderProgramBase(source) {
    use();
    phongVector = getUniform("phongVector");
    shininess = getUniform("shininess");
}
