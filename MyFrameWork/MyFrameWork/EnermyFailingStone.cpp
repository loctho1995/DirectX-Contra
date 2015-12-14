#include "EnermyFailingStone.h"


EnermyFailingStone::EnermyFailingStone(float respawnX, float respawnY)
{
	pData = new EnermyFailingStoneData();
	pData->x = respawnX;
	pData->y = respawnY;

	this->initTextureArrays(EnermyFailingStoneData::COUNT);
	//this->addTextureArray(EnermyFailingStoneData::APPEAR, "appear", 4, 6);
	pData->ppTextureArrays[EnermyFailingStoneData::APPEAR] = new TextureArray("Resources\\Sprites", "failingstone", "appear", 1, 60);
	pData->ppTextureArrays[EnermyFailingStoneData::APPEAR]->setAnchorPoint(0.5f, 1.0f);

	pData->ppTextureArrays[EnermyFailingStoneData::DROP] = new TextureArray("Resources\\Sprites", "failingstone", "appear", 4, 6);
	pData->ppTextureArrays[EnermyFailingStoneData::DROP]->setAnchorPoint(0.5f, 1.0f);

	pData->ppTextureArrays[EnermyFailingStoneData::DEAD] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 8);
	pData->ppTextureArrays[EnermyFailingStoneData::DEAD]->setAnchorPoint(0.5f, 1.0f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-8.0f, -16.0f, 16.0f, 16.0f);
	pData->HP = 8;
	pData->pState = new EnermyFailingStoneAppearingState(pData);
}


EnermyFailingStone::~EnermyFailingStone()
{
}

void EnermyFailingStone::draw(Camera* cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else if (pData->dir.isLeft())
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void EnermyFailingStone::update()
{
	pData->pState->onUpdate();
}

void EnermyFailingStone::loadResources()
{
	TextureArray* temp = new TextureArray("Resources\\Sprites", "failingstone", "appear", 4, 6);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 8);
	delete temp;
}

void EnermyFailingStone::playBeShootedEffect()
{
	Sound::getInstance()->play("beShooted", false, 1);
}