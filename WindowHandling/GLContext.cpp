//
// Created by viktor on 2021-01-29.
//

#include <memory>
#include <GL/glew.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include "GLContext.h"

GLContext::GLContext(SDL_Window *window) {
    setSDLAttributes();
    createGLContext(window);
    SDL_GL_SetSwapInterval(1);
    initialzeGlew();
    setupSync();
    glEnable(GL_DEPTH_TEST);
}

void GLContext::setupSync() const {
    if (SDL_GL_SetSwapInterval(1) < 0) {
        throw std::runtime_error("Unable to set VSync! SDL Error: " + std::string(SDL_GetError()));
    }
}

void GLContext::initialzeGlew() const {
    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        throw std::runtime_error("Error initializing GLEW: " + std::string(reinterpret_cast<const char *>(glewGetErrorString(glewError))) + "\n");
    }
}

void GLContext::createGLContext(SDL_Window *window) {
    glContext = SDL_GL_CreateContext(window);
    if (glContext == nullptr) {
        throw std::runtime_error("Unable to Create GL Context! SDL Error: " + std::string(SDL_GetError()));
    }
}

void GLContext::setSDLAttributes() const {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}


GLContext::~GLContext() {
    SDL_GL_DeleteContext(glContext);
}
