#include "ObjectStaticWeaponData.h"


ObjectStaticWeaponData::ObjectStaticWeaponData()
{
    this->objectName = "staticweapon";

    this->isDesTroyed = false;
    this->isAffectble = true;
    this->isHittable = true;      
    this->isEnemyCollisionable = false;
    this->isPlayerCollisionable = false;
}


ObjectStaticWeaponData::~ObjectStaticWeaponData()
{
}
