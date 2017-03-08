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
	bool loadFromFile(std::string path);
	void free();
	void render(int x, int y);
	int getWidth();
	int getHeight();
	void printErrors(std::string message);
private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
};

#endif // LTEXTURE_H
