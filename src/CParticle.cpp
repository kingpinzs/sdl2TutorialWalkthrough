#include "../header/CParticle.h"

CParticle::CParticle( int x, int y )
{
	mPosX = x - 5 + (rand() % 25);
    mPosY = y - 5 + (rand() % 25);
	
	mFrame = rand() % 5;
	
}

CParticle::~CParticle()
{
}

