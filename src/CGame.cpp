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
		const float time_delta = (SDL_GetTicks() - time_start);
		const float DELAY_TIME = 1000.0 / 60;

		if(time_delta < DELAY_TIME) {
			SDL_Delay((int)(DELAY_TIME-time_delta));
		}
		//std::cout<<1000 / time_delta<<"\n";
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
