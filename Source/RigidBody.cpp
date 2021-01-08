#include "RigidBody.h"

RigidBody::RigidBody(float mass, float gravity) :
  mass(mass), gravity(gravity) {}

void RigidBody::update(float dt) {
  acceleration.x = (force.x + 0) / mass; // friction.x is currently set to 0
  acceleration.y = gravity + (force.y / mass);
  velocity = acceleration * 1; // dt is currently set to 1 so that dt is proportional with position and framerate
  postion = velocity * dt;

  // Make sure that dt is proportional with these values. Before it was dt * dt to find new position,
  // that is why when the framerate is higher than targeted frame rate everything was slower.
  // Fix both axis
}

void RigidBody::setMass(float mass) {
  this->mass = mass;
}

void RigidBody::setGravity(float gravity) {
  this->gravity = gravity;
}

void RigidBody::setForce(Vector force) {
  this->force = force;
}

void RigidBody::setForceX(float forceX) {
  force.x = forceX;
}
    
void RigidBody::setForceY(float forceY) {
  force.y = forceY;
}

void RigidBody::setFriction(Vector friction) {
  this->friction = friction;
}

float RigidBody::getMass() {
  return mass;
}

float RigidBody::getGravity() {
  return gravity;
}

Vector RigidBody::getForce() {
  return force;
}

Vector RigidBody::getFriction() {
  return friction;
}

Vector RigidBody::getPosition() {
  return postion;
}

Vector RigidBody::getVelocity() {
  return velocity;
}

Vector RigidBody::getAcceleration() {
  return acceleration;
}
