#include "Character.h"

Character::Character(std::string textureID, int x, int y, int w, int h, int scale, SDL_RendererFlip flip) :
  GameObject(textureID, x, y, w, h, scale, flip) {
    animation = new Animation(textureID, 0, 4, 200);
    rigidBody = new RigidBody();
}

Character::~Character() {
  delete animation;
  delete rigidBody;
}

void Character::update(float dt) {
  rigidBody->update(0.1);
  transform->translate(rigidBody->getPosition());
  animation->update();
}

void Character::draw() {
  animation->draw(transform->x, transform->y, w, h, scale, flip);
}

void Character::clean() {
  
}
