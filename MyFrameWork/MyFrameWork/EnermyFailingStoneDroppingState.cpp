#include "EnermyFailingStoneDroppingState.h"


EnermyFailingStoneDroppingState::EnermyFailingStoneDroppingState(EnermyData* pData)
{
	this->pData = pData;
	this->pData->iCurrentArr = EnermyFailingStoneData::DROP;
	this->pData->isThrougable = false;
	this->pData->vy = 0.0f;
	acceleration = 0.1f;
	status = 0;
}


EnermyFailingStoneDroppingState::~EnermyFailingStoneDroppingState()
{
}

void EnermyFailingStoneDroppingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	this->pData->y += this->pData->vy;
	if (this->pData->vy<-1.5f)
	{
		this->pData->vy = 0;
		Sound::getInstance()->play("stonefailing", false, 1);
	}
	if (this->pData->vy<0)
	{
		this->pData->vy -= acceleration;
	}
	else
	{
		this->pData->vy += acceleration;
	}
	if (this->pData->vy >= 3.0f)
	{
		status = 0;
	}
}

void EnermyFailingStoneDroppingState::onCollision(CollisionRectF rect)
{
	if (rect.type == "throughable" && status == 0)
	{
		this->pData->vy = -0.1f;
		status = 1;
	}
}

void EnermyFailingStoneDroppingState::onDead()
{
	transition(new EnermyFailingStoneDeadState(pData));
}