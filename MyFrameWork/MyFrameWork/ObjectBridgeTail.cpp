#include "ObjectBridgeTail.h"


ObjectBridgeTail::ObjectBridgeTail(float x, float y)
{
    pData = new ObjectBridgeData();
    pData->x = x;
    pData->y = y;
    pData->dir = Direction::createRight();
    pData->vx = pData->vy = 0;

    pData->isAffectble = false;
    pData->isEnemyCollisionable = true;
    pData->isPlayerCollisionable = true;
    pData->isHittable = false;

    this->initTextureArrays(ObjectBridgeData::COUNT);
    this->addTextureArray(ObjectBridgeData::ALIVE, "tail", 3, 10);
    this->addTextureArray(ObjectBridgeData::EXPLOSION, "explosion", ObjectBridgeData::EXPLOSION_TEXTURE_COUNT, ObjectBridgeData::EXPLOSION_FRAMES_TIME);
    //this->pData->ppTextureArrays[ObjectBridgeData::EXPLOSION] = new TextureArray("Resources\\Sprites", "explosion", "", 3, 10);

    this->pData->ppTextureArrays[ObjectBridgeData::ALIVE]->setAnchorPoint(0.0, 0.0);
    this->pData->ppTextureArrays[ObjectBridgeData::EXPLOSION]->setAnchorPoint(0.0, 0.0);
    this->pData->body = RectF(0, 0, 32.0f, 32.0f);
    this->pData->pState = new ObjectBridgeAliveState(this->pData);
}


ObjectBridgeTail::~ObjectBridgeTail()
{
}
