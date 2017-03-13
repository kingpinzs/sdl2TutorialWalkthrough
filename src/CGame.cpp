#include "../header/CGame.h"
#include <iostream>
#include <SDL.h>
#include "../header/Graphics.h"
namespace {
	const char *WINDOW_TITLE = "SDL Tutorial X";
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int FPS = 60;
	const bool SUCCESS = true;
	const bool FAILED = false;
}

CGame::CGame()
{
	window = NULL;
	renderer = NULL;
	//SDL_Init(SDL_INIT_EVERYTHING);
	std::cout << "sdl init";
	SDL_Init(SDL_INIT_VIDEO);
	SDL_ShowCursor(SDL_DISABLE);
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if (window != NULL) {
		std::cout << "window is created";
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer != NULL) {
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			std::cout << "renderer is created";
			eventLoop();
		}
		else {
			std::cout << "renderer is null";
		}
	}
	else {
		std::cout << "window is null";
	}
	
}

CGame::~CGame()
{
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	fooTexture.free();
	SDL_Quit();
}

void CGame::eventLoop()
{
	
	bool QUIT = false;
	SDL_Event sdlEvent;
	while (!QUIT) {
		const int time_start = SDL_GetTicks();
		while (SDL_PollEvent(&sdlEvent)) {
			switch (sdlEvent.type) {
				case SDL_KEYDOWN:
					if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
						QUIT = true;
					}
					break;
				case SDL_QUIT:
					QUIT = true;
					break;
				default:
					break;
			}
		}
		update();
		draw();
		const int time_delta = SDL_GetTicks() - time_start;
		//TODO: Figure out why 10ms gives me 90fps and 60ms gives me 16fps
		SDL_Delay(10);
		const float s_p_f = (SDL_GetTicks() - time_start) / 1000.0;
		const float c_fps = 1 / s_p_f;
		std::cout << "fps: " << c_fps << "\n";
	}
}

void CGame::update()
{

}

void CGame::draw()
{

}

void CGame::printErrors(std::string message)
{
	message = message + " SDL_Error: %s\n";
	printf(message.c_str(), SDL_GetError());
}