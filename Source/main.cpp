#include "Engine.h"
#include "Clock.h"

int main(int argc, char** argv) {
  Engine* gameEngine = Engine::getInstance();
  Clock* gameClock = Clock::getInstance();
  gameEngine->init();
  
  while (gameEngine->isRunning()) {
    gameEngine->events();
    gameEngine->update();
    gameEngine->render();
    gameClock->tick();
  }

  gameEngine->clean();
  return 0;
}
