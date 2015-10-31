#include "ObjectBridgeData.h"


ObjectBridgeData::ObjectBridgeData()
{
    this->objectName = "bridge";
    this->isDesTroyed = false;
    this->isAffectble = true;
    this->isHittable = false;
    isEnemyCollisionable = true;
    isAllowDestroy = false;
    isDestroying = false;
}


ObjectBridgeData::~ObjectBridgeData()
{
}
