//
// Created by viktor on 2021-03-12.
//

#include "GamePartBase.h"
void GamePartBase::setup(){
    try {
        scene->load();
    } catch (std::exception& e) {
        throw std::runtime_error("Could not load Scene!\n" + std::string(e.what()));
    }
    endScene = false;
}

void GamePartBase::run(){
    inputManager->handleInputs();
    scene->draw();
}

bool GamePartBase::endPart() {
    return inputManager->getQuitStatus();
}
