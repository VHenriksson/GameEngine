//
// Created by viktor on 2021-02-24.
//

#include "TestHandler.h"

void TestHandler::handleRIGHT() {
    scene->rotateRight();
}

void TestHandler::handleDOWN() {
    scene->rotateDown();
}

void TestHandler::handleQUIT() {
    *endScene = true;
}

void TestHandler::handleLEFT() {
    scene->rotateLeft();
}

void TestHandler::handleUP() {
    scene->rotateUp();
}

TestHandler::TestHandler(std::shared_ptr<TestScene> scene, bool *endScene) {
    this->scene = scene;
    this->endScene = endScene;
}

void TestHandler::handleLEFT_ROTATE() {
    //scene->rotateLeft();
}

void TestHandler::handleRIGHT_ROTATE() {
    //scene->rotateRight();
}
