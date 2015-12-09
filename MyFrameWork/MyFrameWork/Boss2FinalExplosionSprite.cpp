#include "Boss2FinalExplosionSprite.h"


Boss2FinalExplosionSprite::Boss2FinalExplosionSprite(float x, float y)
{
    this->pData = new SpriteData();
    this->pData->ppTextureArrays = new TextureArray * [1];
    this->pData->iCurrentArr = 0;
    this->pData->x = x;
    this->pData->y = y;
    this->pData->ppTextureArrays[pData->iCurrentArr] = new TextureArray("Resources\\Sprites\\Explosions", "explosion", "", 3, 12);
    this->pData->ppTextureArrays[pData->iCurrentArr]->setAnchorPoint(0.5f, 0.5f);
}


Boss2FinalExplosionSprite::~Boss2FinalExplosionSprite()
{
    delete this->pData;
}

void Boss2FinalExplosionSprite::setPosition(float x, float y)
{
    this->pData->x = x;
    this->pData->y = y;
}

void Boss2FinalExplosionSprite::setPosition(D3DXVECTOR2 pos)
{
    this->pData->x = pos.x;
    this->pData->y = pos.y;
}

bool Boss2FinalExplosionSprite::isFinishAnimation()
{
    return pData->ppTextureArrays[0]->isLastTexture();
}

void Boss2FinalExplosionSprite::update()
{
    this->pData->ppTextureArrays[pData->iCurrentArr]->update();
}

void Boss2FinalExplosionSprite::draw(Camera *cam)
{
    pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}

void Boss2FinalExplosionSprite::drawAtPosition(float x, float y,Camera *cam)
{
    pData->ppTextureArrays[pData->iCurrentArr]->draw(x, y, cam);
}