#include "Character.h"
#include "Input.h"

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
  
  delete animation;
  rigidBody->setForceX(0);
  animation = new Animation("adventurer_idle2", 0, 4, 200);
  
  if (Input::getInstance()->getKeyDown(SDL_SCANCODE_LEFT)) {
    rigidBody->setForceX(-10);
    delete animation;
    animation = new Animation("adventurer_run", 0, 6, 100);
    flip = SDL_FLIP_HORIZONTAL;
  }

  if (Input::getInstance()->getKeyDown(SDL_SCANCODE_RIGHT)) {
    rigidBody->setForceX(10);
    delete animation;
    animation = new Animation("adventurer_run", 0, 6, 100);
    flip = SDL_FLIP_NONE;
  }

  rigidBody->update(0.1);
  transform->translateX(rigidBody->getPosition().x);
  animation->update();
}

void Character::draw() {
  animation->draw(transform->x, transform->y, w, h, scale, flip);
}

void Character::clean() {
  
}
