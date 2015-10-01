#pragma once
#include "SpriteData.h"
class SpriteState
{
public:
	SpriteState() {}
	virtual ~SpriteState() {}
	virtual void onMovePressed( Direction dir ) {}
	virtual void onMoveReleased( Direction dir ) {}
	virtual void onVeticalDirectionPressed( Direction dir ) {}
	virtual void onVeticalDirectionReleased() {}
	virtual void onJumpPressed() {}
	virtual void onJumpRelease() {}
	virtual void onUpdate() {}
	virtual void onCollision(RectF rect) {}
	virtual void onCollision(CollisionRectF rect) {}
	virtual void onFall() {}
	virtual void onMoveVerticalPressed( Direction dir) {}
	virtual void onMoveVerticalReleased( Direction dir) {}
	virtual void onFirePressed() {}
	virtual void onDead() {}
	virtual void onCameraCollision(RectF cameraRect) {}
	
protected:
	virtual void transition(SpriteState* state) 
	{
		pData -> pState = state; 
		delete this;
	}
protected:
	SpriteData* pData;
};