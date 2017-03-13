#pragma once
#include "LTexture.h"

struct SDL_Window;
struct SDL_Renderer;

class CGraphics
{
public:
	CGraphics();
	~CGraphics();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	LTexture fooTexture;
	void loadMedia();
};

