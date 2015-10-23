#include "ObjectBridgeData.h"


ObjectBridgeData::ObjectBridgeData()
{
    this->objectName = "bridge";
    this->isDesTroyed = false;
    this->isAffectble = true;
    this->isEnemyCollisionable = true;
    isAllowDestroy = false;
}


ObjectBridgeData::~ObjectBridgeData()
{
}
