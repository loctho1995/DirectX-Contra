#include "EnermyCannon.h"
#include "EnermyCannonAppearingState.h"
#include "EnermyCannonTurningState.h"

EnermyCannon::EnermyCannon(int respawnX, int respawnY)
{
	pData = new EnermyCannonData();

	pData->x = respawnX;
	pData->y = respawnY;

	this->initTextureArrays(EnermyCannonData::COUNT);
	this->addTextureArray(EnermyCannonData::APPEAR, "appear", 6, 4);
	this->addTextureArray(EnermyCannonData::TURN0, "standzero", 3, 6);
	this->addTextureArray(EnermyCannonData::TURN30, "standthirty", 3, 6);
	this->addTextureArray(EnermyCannonData::TURN60, "standsixty", 3, 6);
	this->addTextureArray(EnermyCannonData::FIRE, "standzero", 3, 6);
	pData->ppTextureArrays[EnermyCannonData::DEAD] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 6, 4);
	pData->ppTextureArrays[EnermyCannonData::DEAD]->setAnchorPoint(0.5f, 0.5f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-32.0f, -32.0f, 32.0f, 32.0f);
	pData->HP = 1;
	pData->pState = new EnermyCannonAppearingState(pData);
	
}

EnermyCannon::~EnermyCannon()
{

}

void EnermyCannon::draw(Camera* cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else if (pData->dir.isLeft())
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);

	for (int i = 0; i < pData->Bullets.size(); i++)
	{
		pData->Bullets[i]->draw(cam);
	}
}
void EnermyCannon::update()
{
	pData->pState->onUpdate();
	for (int i = 0; i < pData->Bullets.size(); i++)
	{
		pData->Bullets[i]->update();
	}
}