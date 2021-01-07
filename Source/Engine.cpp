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
  TextureManager::getInstance()->load("adventurer_idle", "Assets/Pixel Adventure/Main Characters/Pink Man/Idle (32x32).png");
  TextureManager::getInstance()->load("adventurer_run", "Assets/Pixel Adventure/Main Characters/Pink Man/Run (32x32).png");
  TextureManager::getInstance()->load("adventurer_jump", "Assets/Pixel Adventure/Main Characters/Pink Man/Jump (32x32).png");
  TextureManager::getInstance()->load("adventurer_fall", "Assets/Pixel Adventure/Main Characters/Pink Man/Fall (32x32).png");
  adventurer = new Character("adventurer_idle", 0, 400, 32, 32, 2);
  Camera::getInstance()->setTarget(adventurer->getOrigin());
  TextureManager::getInstance()->load("bg2", "Assets/bg2.png");
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
  SDL_RenderClear(renderer);
  TextureManager::getInstance()->drawBackground("bg2", 0, 0, 1920, 640, 0.25);
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
