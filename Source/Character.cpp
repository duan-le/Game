#include "Character.h"
#include "Input.h"
#include "CollisionManager.h"

// Debug includes
#include "SDL2/SDL.h"
#include "Camera.h"
#include "Vector.h"
#include "Engine.h"
#include <iostream>

Character::Character(std::string textureID, int x, int y, int w, int h, int scale, SDL_RendererFlip flip) :
  GameObject(textureID, x, y, w, h, scale, flip) {
    animation = new Animation();
    animation->setProperties(textureID, 0, 4, 200);
    rigidBody = new RigidBody(1, 6);
    collider = new Collider(x, y, w * scale, h * scale);
    collider->setBuffer(10, 10, -20, -11);

    jumpForce = 10;
    jumpTime = 10;
    isJumping = false;
    isGrounded = false;

    // Debug print
    // std::cout << "Scale: " << scale << std::endl;
    // std::cout << x << ", " << y << ", " << w << ", " << h << std::endl; 
    // SDL_Rect r = collider->getHitbox();
    // std::cout << r.x << ", " << r.y << ", " << r.w << ", " << r.h << std::endl; 
}

Character::~Character() {
  delete animation;
  delete rigidBody;
  delete collider;
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

  // if (Input::getInstance()->getKeyDown(SDL_SCANCODE_UP)) {
  //   isJumping = true;
  //   isGrounded = false;
  //   rigidBody->setForceY(-10);
  //   animation->setProperties("adventurer_jump", 0, 1, 50);
  // }

  if (Input::getInstance()->getKeyDown(SDL_SCANCODE_UP) && isGrounded) {
    isJumping = true;
    isGrounded = false;
    rigidBody->setForceY(-20);
    animation->setProperties("adventurer_jump", 0, 1, 50);
  }

  if (Input::getInstance()->getKeyDown(SDL_SCANCODE_UP) && isJumping && jumpTime > 0) {
    jumpTime -= 1;
    rigidBody->setForceY(-20);
    animation->setProperties("adventurer_jump", 0, 1, 50);
  } else {
    isJumping = false;
    jumpTime = 10;
  }

  rigidBody->update(dt);

  lastSafePosition.x = transform->x;
  transform->translateX(rigidBody->getPosition().x);
  collider->update(transform->x, transform->y, w * scale, h * scale);
  if (CollisionManager::getInstance()->isMapCollision(collider->getHitbox()))
    transform->x = lastSafePosition.x;

  lastSafePosition.y = transform->y;
  transform->translateY(rigidBody->getPosition().y);
  collider->update(transform->x, transform->y, w * scale, h * scale);
  if (CollisionManager::getInstance()->isMapCollision(collider->getHitbox())) {
    transform->y = lastSafePosition.y;
    isGrounded = true;
  } else {
    isGrounded = false;
  }

  origin->x = transform->x + w / 2;
  origin->y = transform->y + h / 2;
  animation->update();
}

void Character::draw() {
  animation->draw(transform->x, transform->y, w, h, scale, flip);

  // Debug: Draw hitbox
  Vector camera = Camera::getInstance()->getPosition();
  SDL_Rect r = collider->getHitbox();
  r.x -= camera.x;
  r.y -= camera.y; 
  SDL_RenderDrawRect(Engine::getInstance()->getRenderer(), &r);
}

void Character::clean() {
  
}
