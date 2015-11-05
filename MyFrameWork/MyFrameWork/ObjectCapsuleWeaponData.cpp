#include "ObjectCapsuleWeaponData.h"


ObjectCapsuleWeaponData::ObjectCapsuleWeaponData()
{
	this->objectName = "capsuleweapon";

	this->isDesTroyed = false;
	this->isAffectble = false;
	this->isHittable = true;
	this->isEnemyCollisionable = false;
	this->isPlayerCollisionable = true;
	bulletType = BulletTypes::N;
}


ObjectCapsuleWeaponData::~ObjectCapsuleWeaponData()
{
}
