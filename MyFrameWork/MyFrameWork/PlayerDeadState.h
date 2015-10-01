#pragma once

#include "PlayerState.h"

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


private:
	bool isMoving;
	int nHoldFrames;
	int count;
	float speedX;
	float acceleration;
};