//
// Created by viktor on 2021-02-21.
//

#include "TexturedGeometry.h"
#include "Importer.h"

TexturedGeometry::TexturedGeometry(std::string source) {
    Importer i = Importer(source);
    for(std::shared_ptr<GLMeshBase> mesh : i.getMeshes()){
        this->push_back(mesh);
    }
}

