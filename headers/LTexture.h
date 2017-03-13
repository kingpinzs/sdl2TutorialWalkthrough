#ifndef LTEXTURE_H
#define LTEXTURE_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

class LTexture
{
public:
	LTexture();
	~LTexture();
	bool loadFromFile(std::string path, SDL_Renderer *renderer);
	void free();
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
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
