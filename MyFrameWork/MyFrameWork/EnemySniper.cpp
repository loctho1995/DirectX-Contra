#include "EnemySniper.h"


EnemySniper::EnemySniper(int respawnX, int respawnY, std::vector < BulletSprite*>& bulletSpriteVector, int local)
{
	pData = new EnemySniperData(bulletSpriteVector);
	pData->x = respawnX;
	pData->y = respawnY;
	pData->isThrougable = false;
	pData->stage = local;

	this->initTextureArrays(EnemySniperData::COUNT);

	pData->ppTextureArrays[EnemySniperData::STAND0] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand0", 1, 8);
	pData->ppTextureArrays[EnemySniperData::STAND0]->setAnchorPoint(0.5f, 1.0f);
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
	
    pData->ppTextureArrays[EnemySniperData::HIDING] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "hiding", 1, 8);
    pData->ppTextureArrays[EnemySniperData::HIDING]->setAnchorPoint(0.5f, 1.0f);

	pData->ppTextureArrays[EnemySniperData::HIDING2] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "hiding2", 1, 8);
	pData->ppTextureArrays[EnemySniperData::HIDING2]->setAnchorPoint(0.5f, 1.0f);

    pData->ppTextureArrays[EnemySniperData::SHOWING] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "showing", 1, 8);
    pData->ppTextureArrays[EnemySniperData::SHOWING]->setAnchorPoint(0.5f, 1.0f);

    pData->ppTextureArrays[EnemySniperData::DYING] = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "dying", 1, 10);
    pData->ppTextureArrays[EnemySniperData::DYING]->setAnchorPoint(0.5f, 1.0f);

	pData->ppTextureArrays[EnemySniperData::DEAD] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "type1", 3, 10);
	pData->ppTextureArrays[EnemySniperData::DEAD]->setAnchorPoint(0.5f, 1.0f);

	pData->dir = Direction::createRight();
	pData->body = RectF(-12.0f / 2, -30.0f, 12.0f, 30.0f);
	pData->HP = 1;

    if (pData->stage == 1)
    {
		pData->pState = new EnemySniperTurningState(pData);
    }
	else
		{
			pData->pState = new EnemySniperHidingState(pData);
		}
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

void EnemySniper::die()
{
	pData->pState = new EnemySniperDyingState(this->pData);
}

void EnemySniper::loadResources()
{
	TextureArray* temp;

	// load sprite
	temp = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand0", 1, 8);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand1", 1, 8);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand2", 1, 8);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand3", 1, 8);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand4", 1, 8);
	delete temp;
	temp = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "stand5", 1, 8);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "hiding", 1, 8);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "hiding2", 1, 8);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "showing", 1, 8);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Enermy", "sniper", "dying", 1, 10);
	delete temp;

	temp = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "type1", 3, 10);
	delete temp;
}