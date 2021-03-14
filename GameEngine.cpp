//
// Created by viktor on 2021-01-17.
//

#include <memory>
#include "GameEngine.h"
#include "Scenes/GameScenes/CaterpillarScene.h"
#include "InputManager/InputManagerCaterpillar.h"
#include "GamePart.h"

GameEngine::GameEngine() {
    GamePart<CaterpillarScene,InputManagerCaterpillar> caterpillarPart;
    caterpillarPart.setup();
    run(caterpillarPart);
}

void GameEngine::run(GamePartBase part) {
    try {
        runLoop(part);
    } catch (std::exception& e) {
        throw std::runtime_error("Game Scene chrashed!\n" + std::string(e.what()));
    }
}


void GameEngine::runLoop(GamePartBase part){
    while( !part.endPart() )
    {
        part.run();
        window.updateWindow();
    }
}
