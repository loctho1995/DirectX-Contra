#include "Boss2FinalBody.h"


Boss2FinalBody::Boss2FinalBody(float x, float y)
{
    this->pData = new SpriteData();
    this->pData->ppTextureArrays = new TextureArray * [1];
    this->pData->iCurrentArr = 0;
    this->pData->ppTextureArrays[0] = new TextureArray("Resources\\Sprites", "boss2final", "body", 1, 1);
    this->pData->ppTextureArrays[0]->setAnchorPoint(0.5, 0);
    this->pData->x = x;
    this->pData->y = y;
}


Boss2FinalBody::~Boss2FinalBody()
{
}

void Boss2FinalBody::update()
{

}


void Boss2FinalBody::draw(Camera* cam)
{
    pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}
