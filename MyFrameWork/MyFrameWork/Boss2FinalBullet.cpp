#include "Boss2FinalBullet.h"


Boss2FinalBullet::Boss2FinalBullet(float x, float y, float speed, float angle)
{
    pData = new EnermyData();
    pData->isHittable = false;    
    pData->isDesTroyed = false;
    pData->x = x;
    pData->y = y;
    pData->ppTextureArrays = new TextureArray *[1];
    pData->iCurrentArr = 0;
    pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Bullets", "boss2finalbullet", "", 4, 8);
    pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 0.5f);
    pData->body = RectF(-8, -8, 16, 16);

    pData->pState = new BulletMovingState(pData, speed, angle, 0);
    Sound::getInstance()->play("boss2bulletsound.wav", false, 1);
}

Boss2FinalBullet::~Boss2FinalBullet()
{
}

void Boss2FinalBullet::update()
{
    this->pData->pState->onUpdate();
}

void Boss2FinalBullet::draw(Camera *cam)
{
    pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}
