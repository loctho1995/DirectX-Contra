#include "EnemySniper.h"


EnemySniper::EnemySniper(int respawnX, int respawnY, std::vector < BulletSprite*>& bulletSpriteVector)
{
	pData = new EnemySniperData(bulletSpriteVector);

	pData->x = respawnX;
	pData->y = respawnY;
	pData->isThrougable = false;

	this->initTextureArrays(EnemySniperData::COUNT);


	pData->ppTextureArrays[EnemySniperData::STAND1] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand1", 1, 8);
	pData->ppTextureArrays[EnemySniperData::STAND1]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnemySniperData::STAND2] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand2", 1, 8);
	pData->ppTextureArrays[EnemySniperData::STAND2]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnemySniperData::STAND3] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand3", 1, 8);
	pData->ppTextureArrays[EnemySniperData::STAND3]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnemySniperData::STAND4] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand4", 1, 8);
	pData->ppTextureArrays[EnemySniperData::STAND4]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnemySniperData::STAND5] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand5", 1, 8);
	pData->ppTextureArrays[EnemySniperData::STAND5]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnemySniperData::STAND6] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand6", 1, 8);
	pData->ppTextureArrays[EnemySniperData::STAND6]->setAnchorPoint(0.5f, 1.0f);

	pData->ppTextureArrays[EnemySniperData::FIRE1] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "fire1", 1, 8);
	pData->ppTextureArrays[EnemySniperData::FIRE1]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnemySniperData::FIRE2] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "fire2", 1, 8);
	pData->ppTextureArrays[EnemySniperData::FIRE2]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnemySniperData::FIRE3] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "fire3", 1, 8);
	pData->ppTextureArrays[EnemySniperData::FIRE3]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnemySniperData::FIRE4] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "fire4", 1, 8);
	pData->ppTextureArrays[EnemySniperData::FIRE4]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnemySniperData::FIRE5] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "fire5", 1, 8);
	pData->ppTextureArrays[EnemySniperData::FIRE5]->setAnchorPoint(0.5f, 1.0f);
	pData->ppTextureArrays[EnemySniperData::FIRE6] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "fire6", 1, 8);
	pData->ppTextureArrays[EnemySniperData::FIRE6]->setAnchorPoint(0.5f, 1.0f);

	pData->ppTextureArrays[EnemySniperData::DEAD] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "type1", 3, 10);
	pData->ppTextureArrays[EnemySniperData::DEAD]->setAnchorPoint(0.5f, 1.0f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-12.0f / 2, -30.0f, 12.0f, 30.0f);
	pData->HP = 1;

	pData->pState = new EnemySniperTurningState(pData);
}

EnemySniper::~EnemySniper()
{
}

void EnemySniper::draw(Camera* cam)
{
	if (pData->dir.isRight())
		pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
	else if (pData->dir.isLeft())
		pData->ppTextureArrays[pData->iCurrentArr]->drawFlipX(pData->x, pData->y, cam);
}

void EnemySniper::update()
{
	pData->pState->onUpdate();
}