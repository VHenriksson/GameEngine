//
// Created by viktor on 2021-02-24.
//

#include "InputManagerBase.h"

void InputManagerBase::handleInputs() {
    while( SDL_PollEvent( &event ) != 0 )
    {

        //User requests quit
        if( event.type == SDL_QUIT )
        {
            handleQUIT();
        }
        else if( event.type == SDL_KEYDOWN )
        {
            checkKeyPressed();
        }
    }
}

void InputManagerBase::checkKeyPressed() {//Select surfaces based on key press
    switch( event.key.keysym.sym )
    {
        case SDLK_ESCAPE:
            handleQUIT();
            break;
        case SDLK_d:
            handleRIGHT();
            break;
        case SDLK_a:
            handleLEFT();
            break;
        case SDLK_w:
            handleUP();
            break;
        case SDLK_s:
            handleDOWN();
            break;
        case SDLK_RIGHT:
            handleRIGHT();
            break;
        case SDLK_LEFT:
            handleLEFT();
            break;
        case SDLK_UP:
            handleUP();
            break;
        case SDLK_DOWN:
            handleDOWN();
            break;
        case SDLK_q:
            handleLEFT_ROTATE();
            break;
        case SDLK_e:
            handleRIGHT_ROTATE();
            break;
        case SDLK_SPACE:
            handleSPACE();
            break;
    }
}

bool InputManagerBase::getQuitStatus() {
    return shouldQuit;
}