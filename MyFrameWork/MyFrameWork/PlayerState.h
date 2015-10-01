#pragma once

#include "SpriteState.h"
#include "PlayerData.h"


class PlayerState : public SpriteState
{
public:
	PlayerState() {}
	virtual void transition(PlayerState* state) 
	{
		pData -> pState = state; 
		delete this;
	}
	virtual void onCameraCollision(RectF cameraRect)
	{
		pData -> x = max(pData -> x, cameraRect.x + 20);
		if( pData -> y >= cameraRect.y + cameraRect.height)
		{
			pData -> y = cameraRect.y + cameraRect.height;
			onDead();
		}
	}
	


protected:
	PlayerData* pData;
};