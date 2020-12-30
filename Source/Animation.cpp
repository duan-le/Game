#include "Animation.h"
#include "TextureManager.h"

Animation::Animation(std::string textureID, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip) :
  textureID(textureID), spriteRow(spriteRow), frameCount(frameCount), animationSpeed(animationSpeed), flip(flip) {}

void Animation::update() {
  spriteFrame = (SDL_GetTicks() / animationSpeed) % frameCount;
}

void Animation::draw(float x, float y, int w, int h) {
  TextureManager::getInstance()->drawFrame(textureID, x, y, w, h, spriteRow, spriteFrame);
}
