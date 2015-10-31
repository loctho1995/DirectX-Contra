#include "ObjectStaticWeaponData.h"


ObjectStaticWeaponData::ObjectStaticWeaponData()
{
    this->objectName = "staticweapon";

    this->isDesTroyed = false;
    this->isAffectble = true;
    this->isHittable = true;      
    this->isEnemyCollisionable = true;
    this->isPlayerCollisionable = true;
    bulletType = BulletTypes::N;
}


ObjectStaticWeaponData::~ObjectStaticWeaponData()
{
}
