#include "Graphics.h"



CGraphics::CGraphics()
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	fooTexture.render(0, 0, renderer);
	SDL_RenderPresent(renderer);
}


CGraphics::~CGraphics()
{
}


void CGraphics::loadMedia()
{
	fooTexture.loadFromFile("texture.png", renderer);
}