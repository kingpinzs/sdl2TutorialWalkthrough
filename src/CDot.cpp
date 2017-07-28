#include "../headers/CDot.h"

CDot::CDot()
{
    mPosX = 0;
    mPosY = 0;

	mVelX = 0;
	mVelY = 0;

	for(int i = 0; i < TOTAL_PARTICLES; ++i) {
		particles[i] = new CParticle(mPosX, mPosY);
	}
}

CDot::~CDot()
{
	for(int i = 0; i < TOTAL_PARTICLES; ++i) {
		delete particles[i];
	}
}

void CDot::render()
{
	gDotTexture.render(mPosX, mPosY, renderer);
	renderParticles();
}

void CDot::renderParticles()
{
	for(int i = 0; i < TOTAL_PARTICLES; ++i ) {
		if (particles[i]->isDead()) {
			delete particles[i];
			particles[i] = new CParticle(mPosX, mPosY);
		}
	}

	for(int i = 0; i < TOTAL_PARTICLES; ++i) {
		particles[i]->render();
	}
}

void CDot::loadMedia()
{
	gDotTexture.loadFromFile("dot.bmp", renderer);
}
