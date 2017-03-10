//#define NDEBUG //Speeds up code
//TODO: add fps count
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "LTexture.h"
#include "tinyxml2.h"

using namespace tinyxml2;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const bool SUCCESS = true;
const bool FAILED = false;
bool QUIT = false;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* currentSurface = NULL;

SDL_Event sdlEvent;

SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;

enum KeyPressSurfaces {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

bool init();
bool loadMedia(SDL_Renderer *renderer);
void close();

SDL_Surface* loadSurface( std::string path);
SDL_Texture* loadTexture( std::string path);
SDL_Surface* keyPressSurface[ KEY_PRESS_SURFACE_TOTAL ];

void printErrors(std::string message);

LTexture fooTexture;
LTexture bckgrndTexture;

int main(int argc, char **argv)
{
	if(init() && loadMedia(renderer)) {
		currentSurface = keyPressSurface[ KEY_PRESS_SURFACE_DEFAULT ];
		while(!QUIT) {
			while(SDL_PollEvent( &sdlEvent ) != 0) {
				if(sdlEvent.type == SDL_QUIT) {
					QUIT = true;
				}
			}

			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(renderer);
			fooTexture.render(0,0,renderer);
			SDL_RenderPresent(renderer);
		}
	}

	close();
	return 0;
}

bool init()
{
	if( SDL_Init(SDL_INIT_VIDEO) < 0) {
		printErrors("Failed to initialize!\nSDL could not initialize!");
		return FAILED;
	}

	window = SDL_CreateWindow("SDL Tutorial X", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(window != NULL) {
		//screenSurface = SDL_GetWindowSurface(window);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if(renderer != NULL) {
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			int imgFlags = IMG_INIT_PNG;
			if(IMG_Init(imgFlags) & imgFlags) {
				return SUCCESS;
			}
			printErrors("SDL_image could not initialize");
			return FAILED;
		}
		printErrors("Renderer could not be created!");
		return FAILED;
	}

	printErrors("Failed to initialize!\nWindow could not be created!");
	return FAILED;
}

void close()
{
	/* for clear the surfaces
	for(int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++) {
		SDL_FreeSurface(keyPressSurface[i]);
		keyPressSurface[i] = NULL;
	}*/
	fooTexture.free();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface( std::string path)
{
	SDL_Surface* optimizedSurface = NULL;

	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL) {
		printErrors("Unable to load image");
	}
	optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, 0);
	if(optimizedSurface == NULL) {
		printErrors("Unable to optimize image");
	}
	SDL_FreeSurface(loadedSurface);

	return optimizedSurface;
}

bool loadSurface()
{
	std::string images[] = {"image1.bmp", "image2.bmp", "image3.bmp", "image4.bmp", "image5.bmp"};
	for(int i = KEY_PRESS_SURFACE_DEFAULT; i != KEY_PRESS_SURFACE_TOTAL; i++) {
		keyPressSurface[i] = loadSurface(images[i]);
		if (keyPressSurface[i] == NULL) {
			printErrors("Failed to load image!");
			return FAILED;
		}
	}
	return SUCCESS;
}

bool loadMedia(SDL_Renderer *renderer)
{
	if(fooTexture.loadFromFile("texture.png", renderer)) {
		return SUCCESS;
	}
	printErrors("Failed to load texture image!");
	return FAILED;
}

void printErrors(std::string message)
{
	message = message + " SDL_Error: %s\n";
	printf(message.c_str(), SDL_GetError());
}
