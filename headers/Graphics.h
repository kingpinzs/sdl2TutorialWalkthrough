#pragma once
#include "LTexture.h"



struct SDL_Window;
struct SDL_Renderer;

class CGraphics
{
public:
	CGraphics();
	~CGraphics();
	// renders sprite texture to the screen
	void draw();
private:
//he is using sdl surface
//it needs to be replaced with sdl_textures
//screen pointer will be replaced with sdl_window
//and sdl_renderer
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Rect clip;
	LTexture mainTexture;
	LTexture spriteTexture;
	void loadMedia();
};

