#ifndef CPARTICLE_H
#define CPARTICLE_H

#include "LTexture.h"

struct SDL_Renderer;

class CParticle
{
public:
	CParticle( int x, int y );
	void render();
	bool isDead();
	~CParticle();
	void loadMedia();
private:
    int mPosX, mPosY;
    int mFrame;
	SDL_Renderer* renderer;
    LTexture *mTexture;
	LTexture gRedTexture;
	LTexture gGreenTexture;
	LTexture gBlueTexture;
	LTexture gShimmerTexture;
};

#endif // CPARTICLE_H
