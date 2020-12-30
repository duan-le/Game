#include "Clock.h"
#include "SDL2/SDL.h"

Clock* Clock::instance = nullptr;

Clock::Clock() {}

Clock* Clock::getInstance() {
  if (instance != nullptr) {
    return instance;
  } else {
    return instance = new Clock();
  }
}

void Clock::tick() {
  deltaTime = (SDL_GetTicks() - lastTime) * (TARGET_FPS / 1000.0);
  if (deltaTime > TARGET_DELTATIME) {
    deltaTime = TARGET_DELTATIME;
  }
  lastTime = deltaTime;
}

float Clock::getDeltaTime() {
  return deltaTime;
}
