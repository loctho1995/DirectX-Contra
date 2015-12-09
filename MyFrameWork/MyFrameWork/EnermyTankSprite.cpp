#include"EnermyTankSprite.h"
#include"EnermyTankData.h"
#include"EnermyTankStartingState.h"

EnermyTankSprite::EnermyTankSprite(int respawnX, int respawnY, std::vector<BulletSprite*>& bulletSpriteVector)
	: EnermySprite(bulletSpriteVector)
{
	pData = new EnermyTankData(bulletSpriteVector);

	pData->x = respawnX;
	pData->y = respawnY;

	pData->ppTextureArrays = new TextureArray*[13];

	pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "start0", 2, 6);
	pData->ppTextureArrays[0]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[1] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "start1", 2, 6);
	pData->ppTextureArrays[1]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[2] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "start2", 2, 6);
	pData->ppTextureArrays[2]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[3] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "between0", 2, 6);
	pData->ppTextureArrays[3]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[4] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "between1", 2, 6);
	pData->ppTextureArrays[4]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[5] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "between2", 2, 6);
	pData->ppTextureArrays[5]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[6] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "next0", 2, 6);
	pData->ppTextureArrays[6]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[7] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "next1", 2, 6);
	pData->ppTextureArrays[7]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[8] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "next2", 2, 6);
	pData->ppTextureArrays[8]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[9] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "finally0", 2, 6);
	pData->ppTextureArrays[9]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[10] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "finally1", 2, 6);
	pData->ppTextureArrays[10]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[11] = new TextureArray("Resources\\Sprites\\Enermy", "tank", "finally2", 2, 6);
	pData->ppTextureArrays[11]->setAnchorPoint(0.1f, 1.0f);

	pData->ppTextureArrays[12] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 8);
	pData->ppTextureArrays[12]->setAnchorPoint(0.5f, 1.0f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-97/10*1.0f, -62.0f, 97.0f, 62.0f);
	//pData->body = RectF(-24.0f, -65.0f, 24.0f, 65.0f);
	pData->pState = new EnermyTankStartingState(pData,0,40);

}

void EnermyTankSprite::draw(Camera *cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else if (pData->dir.isLeft())
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void EnermyTankSprite::update()
{
	pData->pState->onUpdate();
}

void EnermyTankSprite::loadResources()
{
	TextureArray* temp;

	// load sprite
	temp = new TextureArray("Resources\\Sprites\\Enermy", "tank", "start", 6, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enermy", "tank", "between", 6, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enermy", "tank", "next", 6, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enermy", "tank", "finally", 6, 6);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 8);
	delete temp;
}


 EnermyTankSprite::~EnermyTankSprite()
{

}