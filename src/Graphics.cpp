#include "../headers/Graphics.h"
namespace {
	const char *WINDOW_TITLE = "SDL Tutorial X";
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const bool SUCCESS = true;
	const bool FAILED = false;
}

CGraphics::CGraphics()
{
	/*
	 * replace sdl_setvideomode with
	 * sdl create window  then create sdl create renderer
	 */
	
	window = NULL;
	renderer = NULL;
	window = SDL_CreateWindow(
			WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			0
			);
	if (window != NULL) {
		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_ShowCursor(SDL_DISABLE);
		if (renderer != NULL) {
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			loadMedia();
		}
	}
	/*
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	mainTexture.render(0, 0, renderer);
	SDL_RenderPresent(renderer);*/
}

void CGraphics::draw()
{
	clip.h = 32;
	clip.w = 32;
	clip.x = 0;
	clip.y = 0;
	SDL_RenderClear(renderer);
	mainTexture.render(0, 0, renderer);
	spriteTexture.render(60, 60, renderer, &clip);
	SDL_RenderPresent(renderer);
}

CGraphics::~CGraphics()
{
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	mainTexture.free();
	spriteTexture.free();
}


void CGraphics::loadMedia()
{
	mainTexture.loadFromFile("texture.png", renderer);
	spriteTexture.loadFromFile("MyChar.png", renderer);
}
