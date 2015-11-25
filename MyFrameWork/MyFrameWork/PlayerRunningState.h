#pragma once
#include "PlayerState.h"



class PlayerRunningState: public PlayerState
{
public:
	~PlayerRunningState() {}
	PlayerRunningState(PlayerData* data);

	void onMovePressed(Direction d);
	void onMoveReleased(Direction d);
	void onUpdate() ;
	void onJumpPressed();
	void onCollision(RectF rect );
	void onCollision(CollisionRectF rect );
	void onDynamicObjectCollision(CollisionRectF* rect);
	void onFall();
	void onFirePressed();
	void onVeticalDirectionPressed( Direction d);
	void onVeticalDirectionReleased();
	virtual void onDead();

private:
	float speed;
	Direction tempDir;
};