#ifndef CDOT_H
#define CDOT_H

#include "CParticle.h"

struct SDL_Renderer;

class CDot
{
public:
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;
	static const int DOT_VEL = 10;
	static const int TOTAL_PARTICLES = 20;

	CDot();
	~CDot();

	void handleEvent(SDL_Event& e);
	void move();
	void render();
	void loadMedia();

private:
	LTexture gDotTexture;
	CParticle* particles[TOTAL_PARTICLES];
	SDL_Renderer* renderer;
	void renderParticles();
	int mPosX, mPosY;
	int mVelX, mVelY;
};

#endif
