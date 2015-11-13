#include"EnermyGunRotating.h"
#include"EnermyGunRotatingData.h"

EnermyGunRotating::EnermyGunRotating(float respawnX, float respawnY, std::vector < BulletSprite*>& bulletSpriteVector) :EnermySprite(bulletSpriteVector)
{
	pData = new EnermyGunRotatingData(bulletSpriteVector);
	pData->x = respawnX;
	pData->y = respawnY;

	this->initTextureArrays(EnermyGunRotatingData::COUNT);
	this->addTextureArray(EnermyGunRotatingData::CLOSE, "close",1,6);
	pData->ppTextureArrays[EnermyGunRotatingData::CLOSE]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::OPEN, "open", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::OPEN]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL1, "swavel1", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL1]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL2, "swavel2", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL2]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL3, "swavel3", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL3]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL4, "swavel4", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL4]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL5, "swavel5", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL5]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL6, "swavel6", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL6]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL7, "swavel7", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL7]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL8, "swavel8", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL8]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL9, "swavel9", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL9]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL10, "swavel10", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL10]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL11, "swavel11", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL11]->setAnchorPoint(0.5f, 0.5f);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL12, "swavel12", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::SWAVEL12]->setAnchorPoint(0.5f, 0.5f);
	pData->ppTextureArrays[EnermyGunRotatingData::DIE] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 16);
	pData->ppTextureArrays[EnermyGunRotatingData::DIE]->setAnchorPoint(0.5f, 0.5f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-16.0f, -32.0f, 32.0f, 32.0f);
	pData->pState = new EnermyGunRotatingClosingState(pData);
	
}

EnermyGunRotating::~EnermyGunRotating()
{
	
}

void EnermyGunRotating::draw(Camera *cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else if (pData->dir.isLeft())
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void EnermyGunRotating::update()
{
	pData->pState->onUpdate();
}

