#include "Engine.h"
#include "SDL2/SDL.h"
#include <iostream>
#include <algorithm>

int main(int argc, char** argv) {
  Engine* gameEngine = Engine::getInstance();
  gameEngine->init();

  const float MS_PER_SEC = 1000;
  const float TARGET_FPS = 60;
  const float MAX_DELTA_TIME = 1;
  const float TARGET_FRAME_TIME = MS_PER_SEC / TARGET_FPS;
  const float FPS_LIMIT = MS_PER_SEC / 30;
  const bool CAP_FPS = true;


  Uint32 prevTicks = SDL_GetTicks();
  
  while (gameEngine->isRunning()) {

    Uint32 currentTicks = SDL_GetTicks();
    float frameTime = currentTicks - prevTicks;
    prevTicks = currentTicks;
    float totalDeltaTime = frameTime / TARGET_FRAME_TIME;
    std::cout << "frameTime: " << frameTime << std::endl;

    gameEngine->events();

    while (totalDeltaTime > 0.0f) {
      float deltaTime = std::min(totalDeltaTime, MAX_DELTA_TIME);
      std::cout << "deltaTime: " << deltaTime << std::endl;
      gameEngine->update(deltaTime);
      totalDeltaTime -= deltaTime;
    }

    gameEngine->render();

    float totalFrameTime = SDL_GetTicks() - currentTicks;
    std::cout << "totalFrameTime: " << totalFrameTime << std::endl;
    if (CAP_FPS && FPS_LIMIT > totalFrameTime) {
      SDL_Delay(FPS_LIMIT - totalFrameTime);
    }
  }

  gameEngine->clean();
  return 0;
}
