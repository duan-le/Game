#include "Engine.h"

Engine* Engine::instance = nullptr;

Engine::Engine() {}
Engine::~Engine() {}

Engine* Engine::getInstance() {
  if (instance != nullptr) {
    return instance;
  } else {
    return instance = new Engine();
  }
}

void Engine::init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
  } else {
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		renderer = SDL_CreateRenderer(window, -1, 0);
		running = true;
  }

  TextureManager::getInstance()->load("adventurer", "Assets/adventurer_idle1.png");
}

void Engine::events() {
  SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			running = false;
			break;
    
    default:
      break;
  }
}

void Engine::update() {

}

void Engine::render() {
  SDL_SetRenderDrawColor(renderer, 197, 239, 247, 1);
  SDL_RenderClear(renderer);
  TextureManager::getInstance()->draw("adventurer", 0, 0, 50, 37);
  SDL_RenderPresent(renderer);
}

void Engine::clean() {
  TextureManager::getInstance()->clean();
  SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
