#include "Animation.h"
#include "TextureManager.h"

void Animation::update() {
  spriteFrame = (SDL_GetTicks() / animationSpeed) % frameCount;
}

void Animation::draw(float x, float y, int w, int h, int scale, SDL_RendererFlip flip) {
  TextureManager::getInstance()->drawFrame(textureID, x, y, w, h, spriteRow, spriteFrame, scale, flip);
}

void Animation::setProperties(std::string textureID, int spriteRow, int frameCount, int animationSpeed) {
  this->textureID = textureID;
  this->spriteRow = spriteRow;
  this->frameCount = frameCount;
  this->animationSpeed = animationSpeed;
}
