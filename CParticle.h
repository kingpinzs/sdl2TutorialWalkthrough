#ifndef CPARTICLE_H
#define CPARTICLE_H

#include "LTexture.h"

class CParticle
{
public:
	CParticle( int x, int y );
	void render();
	bool isDead();
	~CParticle();
private:
    int mPosX, mPosY;
    int mFrame;
    LTexture *mTexture;	
};

#endif // CPARTICLE_H
