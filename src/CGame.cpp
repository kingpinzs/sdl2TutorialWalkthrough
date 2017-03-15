#include "../headers/CGame.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "../headers/Graphics.h"
namespace {
	const int FPS = 60;
}

CGame::CGame()
{
	SDL_Init(SDL_INIT_VIDEO);
	eventLoop();
}

CGame::~CGame()
{
	SDL_Quit();
}

void CGame::eventLoop()
{
	CGraphics graphics;
	SDL_Event sdlEvent;
	bool QUIT = false;
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
		graphics.draw();
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