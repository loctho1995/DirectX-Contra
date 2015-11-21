#pragma once
#include "PlayerState.h"



class PlayerSwimmingState: public PlayerState
{
public:
	~PlayerSwimmingState() {}
	PlayerSwimmingState(PlayerData* data);

	void onMovePressed(Direction d);
	void onMoveReleased(Direction d);
	void onUpdate() ;
	void onCollision(RectF rect );
	void onCollision(CollisionRectF rect );
	void onFirePressed();
	void onVeticalDirectionPressed( Direction d);
	void onVeticalDirectionReleased();
	virtual void onDead();

private:
	float speed;
	Direction tempDir;
};