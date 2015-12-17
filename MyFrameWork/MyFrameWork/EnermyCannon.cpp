#include "EnermyCannon.h"

EnermyCannon::EnermyCannon(int respawnX, int respawnY, int isStage, std::vector < BulletSprite*>& bulletSpriteVector)
	: 
	EnermySprite(bulletSpriteVector)
{
	pData = new EnermyCannonData(bulletSpriteVector);
	pData->x = respawnX;
	pData->y = respawnY;

	pData->stage = isStage;

	this->initTextureArrays(EnermyCannonData::COUNT);
	this->addTextureArray(EnermyCannonData::PREPARE, "prepare", 1, 60);
	pData->ppTextureArrays[EnermyCannonData::PREPARE]->setAnchorPoint(0.5f, 1.0f);
	this->addTextureArray(EnermyCannonData::APPEAR, "appear", 6, 5);
	pData->ppTextureArrays[EnermyCannonData::APPEAR]->setAnchorPoint(0.5f, 1.0f);
	this->addTextureArray(EnermyCannonData::TURN0, "standzero", 3, 6);
	pData->ppTextureArrays[EnermyCannonData::TURN0]->setAnchorPoint(0.5f, 1.0f);
	this->addTextureArray(EnermyCannonData::TURN30, "standthirty", 3, 6);
	pData->ppTextureArrays[EnermyCannonData::TURN30]->setAnchorPoint(0.5f, 1.0f);
	this->addTextureArray(EnermyCannonData::TURN60, "standsixty", 3, 6);
	pData->ppTextureArrays[EnermyCannonData::TURN60]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnermyCannonData::DEAD] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 10);
	pData->ppTextureArrays[EnermyCannonData::DEAD]->setAnchorPoint(0.5f, 1.0f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-16.0f, -32.0f, 32.0f, 32.0f);
	pData->HP = 8;
	pData->pState = new EnermyCannonPreaparingState(pData);
	
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
}

void EnermyCannon::update()
{
	pData->pState->onUpdate();
}

void EnermyCannon::loadResources()
{
	TextureArray* temp = new TextureArray("Resources\\Sprites\\cannon", "appear", "", 6, 5);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\cannon", "standzero", "", 3, 6);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\cannon", "standthirty", "", 3, 6);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\cannon", "standsixty", "", 3, 6);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 10);
	delete temp;
}

void EnermyCannon::playBeShootedEffect()
{
	Sound::getInstance()->play("beShooted", false, 1);
}