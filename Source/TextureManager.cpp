#include "TextureManager.h"
#include "Engine.h"
#include "Vector.h"
#include "Camera.h"

TextureManager* TextureManager::instance = nullptr;

TextureManager::TextureManager() {}

TextureManager* TextureManager::getInstance() {
  if (instance != nullptr) {
    return instance;
  } else {
    return instance = new TextureManager();
  }
}

void TextureManager::load(std::string id, std::string filepath) {
  SDL_Texture* texture = IMG_LoadTexture(Engine::getInstance()->getRenderer(), filepath.c_str());
  textureMap[id] = texture;
}

void TextureManager::draw(std::string id, int x, int y, int w, int h, SDL_RendererFlip flip) {
  SDL_Rect src = {0, 0, w, h};
  SDL_Rect dest = {x, y, w, h};
  SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), textureMap[id], &src, &dest, 0, nullptr, flip);
}

void TextureManager::drawBackground(std::string id, int x, int y, int w, int h, float scrollSpeed, SDL_RendererFlip flip) {
  Vector camera = Camera::getInstance()->getPosition() * scrollSpeed;
  SDL_Rect src = {0, 0, w, h};
  SDL_Rect dest = {x - (int)(camera.x), y - (int)(camera.y), w, h};
  SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), textureMap[id], &src, &dest, 0, nullptr, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int w, int h, int row, int frame, int scale, SDL_RendererFlip flip) {
  Vector camera = Camera::getInstance()->getPosition();
  SDL_Rect src = {w * frame, h * row, w, h};
  SDL_Rect dest = {x - (int)(camera.x), y - (int)(camera.y), w * scale, h * scale};
  SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), textureMap[id], &src, &dest, 0, nullptr, flip);
}

void TextureManager::drawTile(std::string id, int x, int y, int tileSize, int row, int frame, int scale, SDL_RendererFlip flip) {
  Vector camera = Camera::getInstance()->getPosition();
  SDL_Rect src = {tileSize * frame, tileSize * row, tileSize, tileSize};
  SDL_Rect dest = {x * scale - (int)(camera.x), y * scale - (int)(camera.y), tileSize * scale, tileSize * scale};
  SDL_RenderCopyEx(Engine::getInstance()->getRenderer(), textureMap[id], &src, &dest, 0, nullptr, flip);
}

void TextureManager::drop(std::string id) {
  SDL_DestroyTexture(textureMap[id]);
  textureMap.erase(id);
}

void TextureManager::clean() {
  for (auto& it : textureMap) {
    SDL_DestroyTexture(it.second);
  }
  textureMap.clear();
}
