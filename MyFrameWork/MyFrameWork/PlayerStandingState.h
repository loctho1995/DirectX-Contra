#pragma once

#include "PlayerState.h"

class PlayerStandingState : public PlayerState
{
private:
public:
	~PlayerStandingState() {}
	PlayerStandingState(PlayerData* data);
	void onMovePressed(Direction d) ;
	void onJumpPressed();
	void onUpdate();
	void onVeticalDirectionPressed(Direction d);
	void onVeticalDirectionReleased();
	void onFirePressed();
	void onFall();
	virtual void onDead();
};