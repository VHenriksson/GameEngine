//
// Created by viktor on 2021-02-18.
//

#include "GeometryList.h"
#include "../Objects/GLMesh/hashFunction.h"
#include "../Objects/TexturedGeometry.h"


std::shared_ptr<Geometry> GeometryList::operator[](std::string objectName) {
    std::cout << "Getting object " << objectName << std::endl;
    return this->at(getHash(objectName));
}

void GeometryList::set(std::string name, Geometry geometry) {
    std::cout << "Setting object " << name << std::endl;
    this->insert(std::make_pair(getHash(name),std::make_shared<Geometry>(geometry)));
}

void GeometryList::set(std::string name, std::string source) {
    this->insert(std::make_pair(getHash(name),std::make_shared<Geometry>(TexturedGeometry(source))));
}

void GeometryList::setTextured(std::string name, std::string source) {
    this->insert(std::make_pair(getHash(name),std::make_shared<TexturedGeometry>(TexturedGeometry(source))));
}
