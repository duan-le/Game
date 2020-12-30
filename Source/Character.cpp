#include "Character.h"

Character::Character(std::string textureID, int x, int y, int w, int h, SDL_RendererFlip flip) :
  GameObject(textureID, x, y, w, h, flip) {
    a = new Animation(textureID, 0, 4, 200, flip);
}

void Character::update() {
  a->update();
}

void Character::draw() {
  a->draw(t->getX(), t->getY(), w, h);
}

void Character::clean() {
  
}
