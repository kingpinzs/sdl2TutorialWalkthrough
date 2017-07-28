#include "../headers/CParticle.h"

CParticle::CParticle( int x, int y )
{
	mPosX = x - 5 + (rand() % 25);
    mPosY = y - 5 + (rand() % 25);

	mFrame = rand() % 5;

	switch(rand() % 3) {
		case 0:
		    mTexture = &gRedTexture;
			break;
		case 1:
             mTexture = &gGreenTexture;
			 break;
        case 2:
             mTexture = &gBlueTexture;
			 break;
	}

}

CParticle::~CParticle()
{
}

void CParticle::render()
{
	mTexture->render(mPosX, mPosY, renderer);

	if(mFrame%2 == 0) {
		gShimmerTexture.render(mPosX, mPosY, renderer);
	}

	mFrame++;
}

bool CParticle::isDead()
{
	return mFrame > 10;
}

void CParticle::loadMedia()
{
	gRedTexture.loadFromFile("red.bmp", renderer);
	gGreenTexture.loadFromFile("green.bmp", renderer);
	gBlueTexture.loadFromFile("blue.bmp", renderer);
	gShimmerTexture.loadFromFile("shimmer.bmp", renderer);

	gRedTexture.setAlpha(192);
	gGreenTexture.setAlpha(192);
	gBlueTexture.setAlpha(192);
	gShimmerTexture.setAlpha(192);
}
