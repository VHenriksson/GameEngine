//
// Created by viktor on 2021-01-17.
//

#include <memory>
#include "GameEngine.h"
#include "Scenes/GameScenes/TestScene.h"
#include "InputManager/TestHandler.h"

GameEngine::GameEngine() {
    currentScene = std::make_shared<TestScene>(TestScene());
    currentInputManager = std::make_shared<TestHandler>(TestHandler(std::dynamic_pointer_cast<TestScene>(currentScene),&endCurrentScene));
    tryRun();
}

void GameEngine::tryRun() {
    try {
        runScene();
    } catch (std::exception& e) {
        throw std::runtime_error("Game Scene chrashed!\n" + std::string(e.what()));
    }
}

void GameEngine::runScene() {
    currentScene->load();
    endCurrentScene = false;
    while( !endCurrentScene )
    {
        currentInputManager->handleInputs();
        currentScene->draw();
        window.updateWindow();
    }
}

