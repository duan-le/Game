#include "Engine.h"
#include "Input.h"
#include "TextureManager.h"
#include "Character.h"
#include "MapParser.h"
#include "Camera.h"
#include <iostream>

Engine* Engine::instance = nullptr;
Character* adventurer = nullptr;

Engine::Engine() {}

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
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
		running = true;
  }
  
  MapParser::getInstance()->load();
  currentMap = MapParser::getInstance()->getMap("map1");
  TextureManager::getInstance()->load("adventurer_idle2", "Assets/adventurer_idle2.png");
  TextureManager::getInstance()->load("adventurer_run", "Assets/adventurer_run.png");
  adventurer = new Character("adventurer_idle2", 0, 400, 50, 37, 2);
  Camera::getInstance()->setTarget(adventurer->getOrigin());
}

void Engine::events() {
  Input::getInstance()->listen();
}

void Engine::update() {
  float dt = 1;
  currentMap->update();
  adventurer->update(dt);
  Camera::getInstance()->update(dt);
}

void Engine::render() {
  SDL_SetRenderDrawColor(renderer, 197, 239, 247, 1);
  SDL_RenderClear(renderer);
  currentMap->draw();
  adventurer->draw();
  SDL_RenderPresent(renderer);
}

void Engine::clean() {
  TextureManager::getInstance()->clean();
  SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Engine::quit() {
  running = false;
}

bool Engine::isRunning() {
  return running;
}

SDL_Renderer* Engine::getRenderer() {
  return renderer;
}
