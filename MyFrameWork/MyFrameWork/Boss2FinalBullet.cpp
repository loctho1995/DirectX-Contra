#include "Boss2FinalBullet.h"


Boss2FinalBullet::Boss2FinalBullet(float x, float y, float vx, float vy, float speed)
{
    pData = new SpriteData();
    pData->isHittable = false;
    pData->isDesTroyed = false;
    pData->ppTextureArrays = new TextureArray *[1];
    pData->iCurrentArr = 0;
    pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites\\Bullets", "boss2finalbullet", "", 4, 8);
    pData->ppTextureArrays[0]->setAnchorPoint(0.5f, 0.5f);
    pData->vx = vx;
    pData->vy = vy;
}

Boss2FinalBullet::~Boss2FinalBullet()
{
}

void Boss2FinalBullet::update()
{
    pData->x += pData->vx;
    pData->y += pData->vy;
}

void Boss2FinalBullet::draw(Camera *cam)
{
    pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}
