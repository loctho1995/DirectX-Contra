#pragma once

#include "PlayerState.h"
#include "UIComponents.h"
class PlayerDeadState : public PlayerState
{
public:
	PlayerDeadState(PlayerData * data);
 	~PlayerDeadState() {}
	void onCollision(CollisionRectF rect);
	void onUpdate();
	void onMovePressed(Direction dir);
	void onMoveReleased( Direction dir);
	void onCameraCollision( RectF cameraRect);
	void onVeticalDirectionReleased();


private:
	bool isMoving;
	int nHoldFrames;
	int count;
	float speedX;
	float acceleration;
	Direction tempDir;
};