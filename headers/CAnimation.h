#ifndef CANIMATION_H
#define CANIMATION_H

#include "LTexture.h"

class CAnimation : LTexture 
{
public:
	CAnimation();
	~CAnimation();
	void SetFrameRate(int rate);
	void SetCurrentFrame(int frame);
	int GetCurrentFrame();
private:
	int mMaxFrames;
	int mCurrentFrame;
	int mFrameRate;
	int mFrameInc;
};

#endif // CANIMATION_H
