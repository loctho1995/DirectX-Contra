#include "GunBoss5BulletMovingState.h"


GunBoss5BulletMovingState::GunBoss5BulletMovingState(SpriteData * data)
{
	this->pData = data;
	this->pData->iCurrentArr = 0;
	this->pData->vx = 0.0f;
	this->pData->vy = 1.5f;
}


GunBoss5BulletMovingState::~GunBoss5BulletMovingState()
{
}

void GunBoss5BulletMovingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	pData->x += pData->vx;
	pData->y += pData->vy;
}

void GunBoss5BulletMovingState::onCollision(CollisionRectF rect)
{
	if (rect.type == "nonthroughable")
	{
		transition(new GunBoss5BulletExploringState(pData));
	}
}

void GunBoss5BulletMovingState::onDead()
{
	transition(new GunBoss5BulletExploringState(pData));
}