#include "Animation.h"
#include "TextureManager.h"

void Animation::update() {
  spriteFrame = (SDL_GetTicks() / animationSpeed) % frameCount;
}

void Animation::draw(float x, float y, int w, int h) {
  TextureManager::getInstance()->drawFrame(textureID, x, y, w, h, spriteRow, spriteFrame);
}
