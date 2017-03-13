#include "../header/CAnimation.h"

CAnimation::CAnimation()
{
	mMaxFrames = 0;
	mCurrentFrame = 0;
	mFrameRate = 100;
	mFrameInc= 1;
}

CAnimation::~CAnimation()
{
}

void CAnimation::SetFrameRate(int rate)
{
	mFrameRate = rate;
}

void CAnimation::SetCurrentFrame(int frame)
{
	if(frame < 0 || frame >= mMaxFrames) return;
	
	mCurrentFrame = frame;
}

int CAnimation::GetCurrentFrame() 
{
	return mCurrentFrame;
}