#include "Animation.h"
#include "TextureManager.h"

Animation::Animation(std::string textureID, int spriteRow, int frameCount, int animationSpeed) :
  textureID(textureID), spriteRow(spriteRow), frameCount(frameCount), animationSpeed(animationSpeed) {}

void Animation::update() {
  spriteFrame = (SDL_GetTicks() / animationSpeed) % frameCount;
}

void Animation::draw(float x, float y, int w, int h, int scale, SDL_RendererFlip flip) {
  TextureManager::getInstance()->drawFrame(textureID, x, y, w, h, spriteRow, spriteFrame, scale, flip);
}
