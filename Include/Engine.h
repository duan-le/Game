#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

/**
 * Singleton class
 */
class Engine {
	public:
		~Engine();
		static Engine* getInstance();
		void init();
		void events();
		void update();
		void render();
		void clean();
		inline bool isRunning() {return running;}
		
		
	private:
		bool running;
		Engine();
		static Engine* instance;
		SDL_Window* window;
		SDL_Renderer* renderer;
};
