#pragma once

#include "Engine.h"
#include <map>

class TextureManager {
  public:
    ~TextureManager();
    static TextureManager* getInstance();
    void load(std::string id, std::string filepath);
    void draw(std::string id, int x, int y, int w, int h, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drop(std::string id);
    void clean();

  private:
    TextureManager();
    static TextureManager* instance;
    std::map<std::string, SDL_Texture*> textureMap;
};
