#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "GameMap.h"

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
		
	private:
		Engine();		
		static Engine* instance;
		SDL_Window* window;
		SDL_Renderer* renderer;
		GameMap* currentMap;
		bool running;
};
