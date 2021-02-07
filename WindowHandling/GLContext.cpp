//
// Created by viktor on 2021-01-29.
//

#include <memory>
#include <GL/glew.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "GLContext.h"

GLContext::GLContext(SDL_Window *window) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    glContext = SDL_GL_CreateContext(window);
    if (glContext == nullptr) {
        throw std::runtime_error("Unable to Create GL Context! SDL Error: " + std::string(SDL_GetError()));
    }
    SDL_GL_SetSwapInterval(1);
    //Initialize GLEW
    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        throw std::runtime_error("Error initializing GLEW! %s\n");
        // I should add glewGetErrorString(glewError )
    }

    //Use Vsync
    if (SDL_GL_SetSwapInterval(1) < 0) {
        throw std::runtime_error("Unable to set VSync! SDL Error: " + std::string(SDL_GetError()));

    }
    glEnable(GL_DEPTH_TEST);
}



GLContext::~GLContext() {
    std::cout << "GL context " << this << " sucessfully deleted" << std::endl;
    SDL_GL_DeleteContext(glContext);
}

GLContext::GLContext() {
//    throw std::runtime_error("GLContext construction failed. Needs to be provided with an SDL_Window");
}
