#include "Character.h"
#include "Input.h"

Character::Character(std::string textureID, int x, int y, int w, int h, int scale, SDL_RendererFlip flip) :
  GameObject(textureID, x, y, w, h, scale, flip) {
    animation = new Animation();
    animation->setProperties(textureID, 0, 4, 200);
    rigidBody = new RigidBody(1, 0);
}

Character::~Character() {
  delete animation;
  delete rigidBody;
}

void Character::update(float dt) {
  
  rigidBody->setForceX(0);
  rigidBody->setForceY(0);
  animation->setProperties("adventurer_idle", 0, 11, 100);
  
  if (Input::getInstance()->getKeyDown(SDL_SCANCODE_LEFT)) {
    rigidBody->setForceX(-5);
    animation->setProperties("adventurer_run", 0, 12, 50);
    flip = SDL_FLIP_HORIZONTAL;
  }

  if (Input::getInstance()->getKeyDown(SDL_SCANCODE_RIGHT)) {
    rigidBody->setForceX(5);
    animation->setProperties("adventurer_run", 0, 12, 50);
    flip = SDL_FLIP_NONE;
  }

  if (Input::getInstance()->getKeyDown(SDL_SCANCODE_DOWN)) {
    rigidBody->setForceY(5);
    animation->setProperties("adventurer_fall", 0, 1, 50);
  }

  if (Input::getInstance()->getKeyDown(SDL_SCANCODE_UP)) {
    rigidBody->setForceY(-5);
    animation->setProperties("adventurer_jump", 0, 1, 50);
  }

  rigidBody->update(dt);
  transform->translateX(rigidBody->getPosition().x);
  transform->translateY(rigidBody->getPosition().y);
  origin->x = transform->x + w / 2;
  origin->y = transform->y + h / 2;
  animation->update();
}

void Character::draw() {
  animation->draw(transform->x, transform->y, w, h, scale, flip);
}

void Character::clean() {
  
}
