//
// Created by viktor on 2021-02-24.
//

#include "InputManagerCaterpillar.h"

void InputManagerCaterpillar::handleRIGHT() {
    scene->rotateRight();
}

void InputManagerCaterpillar::handleDOWN() {
    scene->rotateDown();
}

void InputManagerCaterpillar::handleQUIT() {
    shouldQuit = true;
}

void InputManagerCaterpillar::handleLEFT() {
    scene->rotateLeft();
}

void InputManagerCaterpillar::handleUP() {
    scene->rotateUp();
}

InputManagerCaterpillar::InputManagerCaterpillar(std::shared_ptr<CaterpillarScene> scene) {
    this->scene = scene;
}

void InputManagerCaterpillar::handleSPACE() {
    scene->hidePlanet();
}

