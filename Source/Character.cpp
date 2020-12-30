#include "Character.h"

Character::Character(std::string textureID, int x, int y, int w, int h, int scale, SDL_RendererFlip flip) :
  GameObject(textureID, x, y, w, h, scale, flip) {
    animation = new Animation(textureID, 0, 4, 200);
}

Character::~Character() {
  delete animation;
}

void Character::update() {
  animation->update();
}

void Character::draw() {
  animation->draw(transform->getX(), transform->getY(), w, h, scale, flip);
}

void Character::clean() {
  
}
