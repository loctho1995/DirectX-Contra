#pragma once
#include "EnermyState.h"
class EnemyMineFallingState : public EnermyState
{
public:
	EnemyMineFallingState(EnermyData* data);
	~EnemyMineFallingState(void);
	virtual void onUpdate();
	virtual void onCollision(CollisionRectF rect);
private:
	float speedX;
	float speedY;
	float acceleration;
};

