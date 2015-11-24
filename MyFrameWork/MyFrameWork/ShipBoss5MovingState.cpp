#include "ShipBoss5MovingState.h"

ShipBoss5MovingState::ShipBoss5MovingState(SpriteData * data, bool isLeft)
{
	this->pData = data;
	this->pData->iCurrentArr = 0;
	isLeftAppear = isLeft;
	speed = 1.2f;
}

ShipBoss5MovingState::~ShipBoss5MovingState()
{
}

void ShipBoss5MovingState::onUpdate()
{
	pData->ppTextureArrays[pData->iCurrentArr]->update();
	
	switch (isLeftAppear)
	{
	case true:
		if (this->pData->x - this->pData->body.width / 2 >= wallLeft && this->pData->y - this->pData->body.height / 2 <= wallBottom)
		{
			this->pData->vx = -speed;
			this->pData->vy = 0;
		}
		if (this->pData->x - this->pData->body.width / 2 <= wallLeft && this->pData->y - this->pData->body.height / 2 <= wallBottom)
		{
			this->pData->vx = 0;
			this->pData->vy = speed;
		}
		if (this->pData->x - this->pData->body.width / 2 <= wallLeft && this->pData->y - this->pData->body.height / 2 >= wallBottom)
		{
			this->pData->vx = speed;
			this->pData->vy = 0;
		}
		break;
	case false:
		if (this->pData->x + this->pData->body.width / 2 <= wallRight && this->pData->y - this->pData->body.height / 2 <= wallBottom)
		{
			this->pData->vx = speed;
			this->pData->vy = 0;
		}
		if (this->pData->x + this->pData->body.width / 2 >= wallRight && this->pData->y - this->pData->body.height / 2 <= wallBottom)
		{
			this->pData->vx = 0;
			this->pData->vy = speed;
		}
		if (this->pData->x + this->pData->body.width / 2 >= wallRight && this->pData->y - this->pData->body.height / 2 >= wallBottom)
		{
			this->pData->vx = -speed;
			this->pData->vy = 0;
		}
		break;
	}
	this->pData->x += this->pData->vx;
	this->pData->y += this->pData->vy;
}

void ShipBoss5MovingState::onDead()
{
	transition(new ShipBoss5ExploringState(pData));
}