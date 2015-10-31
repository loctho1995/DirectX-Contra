#include "ObjectBridgeHead.h"

ObjectBridgeHead::ObjectBridgeHead(float x, float y)
{
    //toa do ve la goc trai tren

    pData = new ObjectBridgeData();
    pData->x = x;
    pData->y = y;
    pData->dir = Direction::createRight();
    pData->vx = pData->vy = 0;

    this->initTextureArrays(ObjectBridgeData::COUNT);
    this->addTextureArray(ObjectBridgeData::ALIVE, "head", 3, 10);
    this->addTextureArray(ObjectBridgeData::EXPLOSION, "explosion", EXPLOSION_TEXTURE_COUNT, EXPLOSION_FRAMES_TIME);

    this->pData->ppTextureArrays[ObjectBridgeData::ALIVE]->setAnchorPoint(0.0, 0.0);
    this->pData->ppTextureArrays[ObjectBridgeData::EXPLOSION]->setAnchorPoint(0.0, 0.0);

    this->pData->body = RectF(0, 0, 32.0f, 32.0f);
    this->pData->pState = new ObjectBridgeAliveState(this->pData);
}


ObjectBridgeHead::~ObjectBridgeHead()
{

}

bool ObjectBridgeHead::isDestroying()
{
    return ((ObjectBridgeData*)pData)->isDestroying;
}

void ObjectBridgeHead::draw(Camera *cam)
{
    if (!pData->isDesTroyed)
        ObjectSprite::draw(cam);
}
