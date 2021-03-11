//
// Created by viktor on 2021-02-24.
//

#ifndef GAMEENGINE_INPUTMANAGERBASE_H
#define GAMEENGINE_INPUTMANAGERBASE_H


#include <SDL2/SDL_events.h>

class InputManagerBase {
protected:
    SDL_Event event;
    virtual void handleQUIT() = 0;
    virtual void handleUP() = 0;
    virtual void handleDOWN() = 0;
    virtual void handleRIGHT() = 0;
    virtual void handleLEFT() = 0;
    virtual void handleLEFT_ROTATE() = 0;
    virtual void handleRIGHT_ROTATE() = 0;
public:
    void handleInputs();

};



#endif //GAMEENGINE_INPUTMANAGERBASE_H
