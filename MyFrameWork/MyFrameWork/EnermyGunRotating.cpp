#include"EnermyGunRotating.h"
#include"EnermyGunRotatingData.h"

EnermyGunRotating::EnermyGunRotating(float respawnX, float respawnY)
{
	pData = new EnermyGunRotatingData();

	pData->x = respawnX;
	pData->y = respawnY;

	this->initTextureArrays(EnermyGunRotatingData::COUNT);
	this->addTextureArray(EnermyGunRotatingData::CLOSE, "close",1,6);
	this->addTextureArray(EnermyGunRotatingData::OPEN, "open", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL1, "swavel1", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL2, "swavel2", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL3, "swavel3", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL4, "swavel4", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL5, "swavel5", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL6, "swavel6", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL7, "swavel7", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL8, "swavel8", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL9, "swavel9", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL10, "swavel10", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL11, "swavel11", 1, 6);
	this->addTextureArray(EnermyGunRotatingData::SWAVEL12, "swavel12", 1, 6);
	pData->ppTextureArrays[EnermyGunRotatingData::DIE] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 16);
	pData->ppTextureArrays[EnermyGunRotatingData::DIE]->setAnchorPoint(0.5f, 0.5f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-16.0f, -32.0f, 32.0f, 32.0f);
	pData->vx = pData->vy = 0;
	pData->pState = new EnermyGunRotatingClosingState(pData);
	// phai xet anchorPoint cho tat ca array luon
	//body cua ban hinh nhu chua dung roi.
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
	for (int i = 0; i < pData->Bullets.size(); i++)
	{
		pData->Bullets[i]->draw(cam);
	}
}

void EnermyGunRotating::update()
{
	pData->pState->onUpdate();
	for (int i = 0; i < pData->Bullets.size(); i++)
	{
		pData->Bullets[i]->update();
	}
	
}

