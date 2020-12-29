#include "Character.h"

Character::Character(std::string textureID, int x, int y, int w, int h, SDL_RendererFlip flip) :
  GameObject(textureID, x, y, w, h, flip) {
    row = 0;
    frameCount = 4;
    animationSpeed = 120;
}

void Character::update() {
  frame = (SDL_GetTicks() / animationSpeed) % frameCount;
}

void Character::draw() {
  TextureManager::getInstance()->drawFrame(textureID, t->getX(), t->getY(), w, h, row, frame);
}

void Character::clean() {
  TextureManager::getInstance()->clean();
}
