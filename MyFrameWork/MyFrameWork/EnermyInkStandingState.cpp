#include "EnermyInkStandingState.h"

#include "EnermyInkJumpingState.h"


EnermyInkStandingState::EnermyInkStandingState( EnermyData* data)
{
	pData = data;
	pData ->iCurrentArr = 0;
	nHoldFrame = 30;
	count = 0;
}


void EnermyInkStandingState :: onUpdate()
{
	pData ->ppTextureArrays[ pData ->iCurrentArr ] ->update();
	count ++;
	count %= nHoldFrame;
	if( count == 0)
	{
		transition(new EnermyInkJumpingState(pData));
	}
}

