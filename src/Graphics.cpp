#include "../headers/Graphics.h"
namespace {
	const char *WINDOW_TITLE = "SDL Tutorial X";
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int FPS = 60;
	const bool SUCCESS = true;
	const bool FAILED = false;
}

CGraphics::CGraphics()
{
	window = NULL;
	renderer = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_ShowCursor(SDL_DISABLE);
	window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if (window != NULL) {
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer != NULL) {
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		}
	}
	/*
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	fooTexture.render(0, 0, renderer);
	SDL_RenderPresent(renderer);*/
}


CGraphics::~CGraphics()
{
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	fooTexture.free();
}


void CGraphics::loadMedia()
{
	fooTexture.loadFromFile("texture.png", renderer);
}