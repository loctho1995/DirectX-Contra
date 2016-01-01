#include "EnemyMineFallingState.h"
#include "EnemyMineExploringState.h"
#include "Sound.h"
EnemyMineFallingState::EnemyMineFallingState(EnermyData* data)
{
	this -> pData = data;
	pData -> x = pData -> respawnX;
	pData -> y = pData -> respawnY;
	pData -> iCurrentArr = 0;
	speedX = 1.0f;
	speedY = 2.75f;
	acceleration = 0.1f;
	pData -> vx = pData -> transform(speedX);
	pData -> vy = -speedY;
	
}


void EnemyMineFallingState :: onUpdate()
{
	EnermyState::onUpdate();
	pData -> vy += acceleration;
	pData -> x += pData -> vx;
	pData -> y += pData -> vy;
}
void EnemyMineFallingState :: onCollision(CollisionRectF rect)
{
	transition(new EnemyMineExploringState(pData ));
}

EnemyMineFallingState::~EnemyMineFallingState(void)
{
}
