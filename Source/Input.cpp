#include "Input.h"
#include "Engine.h"

Input* Input::instance = nullptr;

Input::Input() {
  keyStates = SDL_GetKeyboardState(nullptr);
}

Input* Input::getInstance() {
  if (instance != nullptr) {
    return instance;
  } else {
    return instance = new Input();
  }
}

void Input::listen() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type)
    {
      case SDL_QUIT:
        Engine::getInstance()->quit();
        break;

      case SDL_KEYDOWN:
        keyDown();
        break;
      
      case SDL_KEYUP:
        keyUp();
        break;
      
      default:
        break;
    }
  }
}

bool Input::getKeyDown(SDL_Scancode key) {
  if (keyStates[key] == 1) {
    return true;
  } else {
    return false;
  }
}

void Input::keyUp() {
  keyStates = SDL_GetKeyboardState(nullptr);
}

void Input::keyDown() {
  keyStates = SDL_GetKeyboardState(nullptr);
}
