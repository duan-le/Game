#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "GameMap.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 640

class Engine {
	public:
		static Engine* getInstance();
		void init();
		void events();
		void update();
		void render();
		void clean();
		void quit();
		bool isRunning();
		SDL_Renderer* getRenderer();
		GameMap* getMap();
		
	private:
		Engine();		
		static Engine* instance;
		SDL_Window* window;
		SDL_Renderer* renderer;
		GameMap* currentMap;
		bool running;
};
