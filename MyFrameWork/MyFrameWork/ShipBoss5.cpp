#include "ShipBoss5.h"


ShipBoss5::ShipBoss5(float x, float y, bool isLeft)
{
	pData = new SpriteData();
	pData->x = x;
	pData->y = y;

	pData->ppTextureArrays = new TextureArray*[2];
	//ship
	pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\finalboss5", "ship", "", 3, 6);
	pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 0.5f);
	//die
	pData->ppTextureArrays[1] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 6);
	pData->ppTextureArrays[1]->setAnchorPoint(0.5f, 0.5f);

	pData->body = RectF(-13.5f, -10.5f, 27.0f, 21.0f);
	pData->pState = new ShipBoss5MovingState(pData, isLeft);
	pData->isDesTroyed = false;
	pData->isHittable = true;
}


ShipBoss5::~ShipBoss5()
{
}

void ShipBoss5::draw(Camera* cam)
{
	pData->ppTextureArrays[this->pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}
void ShipBoss5::update()
{
	pData->pState->onUpdate();
}

void ShipBoss5::die()
{
	pData->pState->onDead();
}