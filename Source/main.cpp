#include "Engine.h"

int main(int argc, char** argv) {
  Engine* gameEngine = Engine::getInstance();
  gameEngine->init();
  
  while (gameEngine->isRunning()) {
    gameEngine->events();
    gameEngine->update();
    gameEngine->render();
  }

  gameEngine->clean();
  return 0;
}
