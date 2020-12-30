#include "RigidBody.h"

RigidBody::RigidBody(float mass, float gravity) :
  mass(mass), gravity(gravity) {}

void RigidBody::update(float dt) {
  acceleration.x = (force.x + friction.x) / mass;
  acceleration.y = gravity + (force.y / mass);
  velocity = acceleration * dt;
  postion = velocity * dt;
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
