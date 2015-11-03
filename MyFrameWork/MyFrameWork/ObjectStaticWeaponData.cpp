#include "ObjectStaticWeaponData.h"


ObjectStaticWeaponData::ObjectStaticWeaponData()
{
    this->objectName = "staticweapon";

    this->isDesTroyed = false;
    this->isAffectble = false;
    this->isHittable = true;      
    this->isEnemyCollisionable = false;
    this->isPlayerCollisionable = true;
    bulletType = BulletTypes::N;
}


ObjectStaticWeaponData::~ObjectStaticWeaponData()
{
}
