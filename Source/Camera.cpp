#include "Camera.h"

Camera* Camera::instance = nullptr;

Camera::Camera() :
  position({0, 0}), viewBox({0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}) {}

Camera* Camera::getInstance() {
  if (instance != nullptr) {
    return instance;
  } else {
    return instance = new Camera();
  }
}

void Camera::update(float dt) {
  if (target != nullptr) {
    viewBox.x = target->x - WINDOW_WIDTH / 2;
    viewBox.y = target->y - WINDOW_HEIGHT / 2;
  }
  if (viewBox.x < 0) {
    viewBox.x = 0;
  }
  if (viewBox.y < 0) {
    viewBox.y = 0;
  }
  if (viewBox.x > (LEVEL_WIDTH- viewBox.w)) {
    viewBox.x = (LEVEL_WIDTH - viewBox.w);
  }
  if (viewBox.y > (LEVEL_HEIGHT - viewBox.h)) {
    viewBox.y = (LEVEL_HEIGHT - viewBox.h);
  }
  position.x = viewBox.x;
  position.y = viewBox.y;
}

Vector Camera::getPosition() {
  return position;
}

SDL_Rect Camera::getViewBox() {
  return viewBox;
}

void Camera::setTarget(Vector* target) {
  this->target = target;
}

