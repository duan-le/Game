#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "TextureManager.h"
#include <iostream>

class Engine {
	public:
		~Engine();
		static Engine* getInstance();
		void init();
		void events();
		void update();
		void render();
		void clean();
		bool isRunning() {return running;}
		SDL_Renderer* getRenderer() {return renderer;}
		
	private:
		bool running;
		Engine();
		static Engine* instance;
		SDL_Window* window;
		SDL_Renderer* renderer;
};
