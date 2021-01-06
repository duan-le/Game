#include "Camera.h"

Camera* Camera::instance = nullptr;

Camera::Camera() :
  viewBox({0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}) {}

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
  if (viewBox.x > (2 * WINDOW_WIDTH - viewBox.w)) {
    viewBox.x = (2 * WINDOW_WIDTH - viewBox.w);
  }
  if (viewBox.y > (2 * WINDOW_HEIGHT - viewBox.h)) {
    viewBox.y = (2 * WINDOW_HEIGHT - viewBox.h);
  }
  if (viewBox.x == WINDOW_WIDTH) {
    viewBox.x = WINDOW_WIDTH;
  }
  if (viewBox.y == WINDOW_HEIGHT) {
    viewBox.y = WINDOW_HEIGHT;
  }
  position = Vector(viewBox.x, viewBox.y);
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

