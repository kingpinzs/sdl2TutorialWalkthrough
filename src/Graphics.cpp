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
	/*
	 * Possible to create window and render at the same time
	 * SDL_CreateWindowAndRenderer()
	 */
	window = SDL_CreateWindow(
			WINDOW_TITLE,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			0
			);
	if (window != NULL) {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		SDL_ShowCursor(SDL_DISABLE);
		if (renderer != NULL) {
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			loadMedia();
		}
	}

	frame = 0;
	/*
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	mainTexture.render(0, 0, renderer);
	SDL_RenderPresent(renderer);*/
}

void CGraphics::draw()
{
	SDL_RenderClear(renderer);
	mainTexture.render(0, 0, renderer);
	spriteTexture.render(60, 60, renderer, &clip[frame]);
	dot.render();
	SDL_RenderPresent(renderer);
	++frame;
	if(frame >= 3) {
		frame =0;
	}
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

	clip[0].h = 32;
	clip[0].w = 32;
	clip[0].x = 0;
	clip[0].y = 0;

	clip[1].h = 32;
	clip[1].w = 32;
	clip[1].x = 32;
	clip[1].y = 0;

	clip[2].h = 32;
	clip[2].w = 32;
	clip[2].x = 64;
	clip[2].y = 0;

}
