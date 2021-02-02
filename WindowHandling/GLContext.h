//
// Created by viktor on 2021-01-29.
//

#ifndef GAMEENGINE_GLCONTEXT_H
#define GAMEENGINE_GLCONTEXT_H



class GLContext {
private:
    SDL_GLContext glContext;
public:
    explicit GLContext(SDL_Window* window);
    GLContext();
    ~GLContext();
};


#endif //GAMEENGINE_GLCONTEXT_H
