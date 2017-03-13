//#define NDEBUG //Speeds up code
//TODO: add fps count
#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "CGame.h"
#include "LTexture.h"
#include "tinyxml2.h"

using namespace tinyxml2;

SDL_Surface* screenSurface = NULL;
SDL_Surface* currentSurface = NULL;

SDL_Texture* texture = NULL;

//bool init();
//bool loadMedia(SDL_Renderer *renderer);
//void close();

SDL_Surface* loadSurface( std::string path);
SDL_Texture* loadTexture( std::string path);

//void printErrors(std::string message);

LTexture fooTexture;
LTexture bckgrndTexture;

//int main(int argc, char **argv)
int main(int argc, char *args[])
{
	CGame game;
	return 0;
}

void close()
{
	/* for clear the surfaces
	for(int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++) {
		SDL_FreeSurface(keyPressSurface[i]);
		keyPressSurface[i] = NULL;
	}*/

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
/*

*/

