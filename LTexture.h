#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class LTexture
{
public:
	LTexture();
	~LTexture();
	bool loadFromFile(std::string path, SDL_Renderer *renderer);
	void free();
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void render(int x, int y, SDL_Renderer *renderer, SDL_Rect* clip = NULL);
	int getWidth();
	int getHeight();
	void printErrors(std::string message);
private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
};

#endif // LTEXTURE_H
