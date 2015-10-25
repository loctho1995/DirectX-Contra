#include "ObjectBridgeTail.h"


ObjectBridgeTail::ObjectBridgeTail(float x, float y)
{
    pData = new ObjectBridgeData();
    pData->x = x;
    pData->y = y;
    pData->dir = Direction::createRight();
    pData->vx = pData->vy = 0;

    this->initTextureArrays(ObjectBridgeData::COUNT);
    this->addTextureArray(ObjectBridgeData::ALIVE, "tail", 3, 10);
    this->addTextureArray(ObjectBridgeData::EXPLOSION, "explosion", EXPLOSION_TEXTURE_COUNT, EXPLOSION_FRAMES_TIME);
    //this->pData->ppTextureArrays[ObjectBridgeData::EXPLOSION] = new TextureArray("Resources\\Sprites", "explosion", "", 3, 10);

    this->pData->ppTextureArrays[ObjectBridgeData::ALIVE]->setAnchorPoint(0.0, 0.0);
    this->pData->ppTextureArrays[ObjectBridgeData::EXPLOSION]->setAnchorPoint(0.0, 0.0);
    this->pData->body = RectF(0, 0, 32.0f, 32.0f);
    this->pData->pState = new ObjectBridgeAliveState(this->pData);
}


ObjectBridgeTail::~ObjectBridgeTail()
{
}

bool ObjectBridgeTail::isDestroying()
{
    return ((ObjectBridgeData*)pData)->isDestroying;
}

void ObjectBridgeTail::draw(Camera *cam)
{
    if (!pData->isDesTroyed)
        ObjectSprite::draw(cam);
}
