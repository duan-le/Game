#pragma once

#include "SDL2/SDL.h"
#include <map>

class TextureManager {
  public:
    static TextureManager* getInstance();
    void load(std::string id, std::string filepath);
    void draw(std::string id, int x, int y, int w, int h, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawBackground(std::string id, int x, int y, int w, int h, float scrollSpeed = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(std::string id, int x, int y, int w, int h, int row, int frame, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawTile(std::string id, int x, int y, int tileSize, int row, int frame, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drop(std::string id);
    void clean();

  private:
    TextureManager();
    static TextureManager* instance;
    std::map<std::string, SDL_Texture*> textureMap;
};
