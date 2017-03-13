//#define NDEBUG //Speeds up code
//TODO: add fps count
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../header/CGame.h"
#include "../header/LTexture.h"
#include "../header/tinyxml2.h"

using namespace tinyxml2;

//int main(int argc, char **argv)
int main(int argc, char *args[])
{
	CGame game;
	return 0;
}

void close()
{

	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface( std::string path)
{
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL) {
		//printErrors("Unable to load image");
	}
	optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, 0);
	if(optimizedSurface == NULL) {
		//printErrors("Unable to optimize image");
	}
	SDL_FreeSurface(loadedSurface);

	return optimizedSurface;
}
