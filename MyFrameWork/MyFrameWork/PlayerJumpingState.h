#pragma once

#include "PlayerState.h"

class PlayerJumpingState : public PlayerState
{
public:
	PlayerJumpingState(PlayerData * data , bool isMoving = false, float vy = -5.0f);
 	~PlayerJumpingState() {}
	void onMovePressed(Direction dir);
	void onMoveReleased( Direction dir);
	void onJumpRelease();
	void onCollision(RectF rect);
	void onCollision(CollisionRectF rect);
	void onDynamicObjectCollision(CollisionRectF* cRect);
	void onUpdate();
	void onFirePressed();
	void onVeticalDirectionPressed( Direction d);
	void onVeticalDirectionReleased();
	virtual void onDead();

private:
	bool isMoving;
	bool isJumpingPress;
	float speedX;
	float acceleration;
	Direction tempDir;

};