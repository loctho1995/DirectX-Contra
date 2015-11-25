#include "Boss2FinalHead.h"


Boss2FinalHead::Boss2FinalHead(float x, float y, std::vector<BulletSprite*>& bulletSprite)
{
    this->pData = new Boss2FinalData(bulletSprite);
    this->pData->botName = "boss2finalhead";
    this->pData->x = x;
    this->pData->y = y;
    this->pData->isDesTroyed = false;
    this->pData->body = RectF(-22.5f, 0, 55, 55);
    this->pData->iCurrentArr = 0;
    this->pData->ppTextureArrays = new TextureArray * [Boss2FinalData::ArrayIndex::COUNT];
    this->pData->ppTextureArrays[Boss2FinalData::ArrayIndex::SHUT] = new TextureArray("Resources\\Sprites", "boss2final", "bodyshut", 3, 15);
    this->pData->ppTextureArrays[Boss2FinalData::ArrayIndex::OPEN] = new TextureArray("Resources\\Sprites", "boss2final", "body", 5, 15);
    this->pData->ppTextureArrays[Boss2FinalData::ArrayIndex::SHUT]->setAnchorPoint(0.5f, 0.0f);
    this->pData->ppTextureArrays[Boss2FinalData::ArrayIndex::OPEN]->setAnchorPoint(0.5f, 0.0f);
    this->pData->pState = new Boss2FinalHeadState(this->pData);
}


Boss2FinalHead::~Boss2FinalHead()
{

}

void Boss2FinalHead::update()
{
    this->pData->pState->onUpdate();
}

void Boss2FinalHead::draw(Camera *cam)
{
    std::cout << "x: " << pData->x << "y: " << pData->y;
    pData->ppTextureArrays[pData->iCurrentArr]->draw(pData->x, pData->y, cam);
}
