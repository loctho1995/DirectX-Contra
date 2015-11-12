#include "EnermyCreator.h"
#include "EnermyInkSprite.h"
#include "EnermyGunBoss1Sprite.h"
#include "EnermyFinalBoss1Sprite.h"
#include "ObjectBridge.h"
#include "EnermyCannon.h"
#include "EnermyGunRotating.h"


EnermyCreator* EnermyCreator::instance = nullptr;

EnermyCreator::EnermyCreator()
{
	// set up the map direction by function addAppearDirection(std::string name , Direction dir )
	addAppearDirection("gunboss1",Direction::createRight());
	addAppearDirection("finalboss1",Direction::createRight());
}

void EnermyCreator::addAppearDirection(std::string name, Direction dir)
{
	appearDirections[name] = dir;
}

EnermyCreator* EnermyCreator::getInstance()
{
	if (instance == nullptr)
	{
		instance = new EnermyCreator();
	}
	return instance;
}

EnermySprite* EnermyCreator::createEnermySprite(std::string enermyName, int respawnX, int respawnY, std :: vector < BulletSprite* >& bulletSprites)
{
	if (enermyName == "ink")
	{
		return new EnermyInkSprite(respawnX, respawnY);
	}

	if (enermyName == "gunrotating")
	{
		return new EnermyGunRotating(respawnX, respawnY);
	}

	if (enermyName == "cannon")
	{
		return new EnermyCannon(respawnX, respawnY);
	}

	if (enermyName == "soldierl")
	{
		return new EnermySoldier(respawnX, respawnY, Direction::createLeft());
	}

    if (enermyName == "soldierr")
    {
        return new EnermySoldier(respawnX, respawnY, Direction::createRight());
    }

	if (enermyName == "sniper")
	{
		return new EnemySniper(respawnX, respawnY);
	}

	if (enermyName == "gunboss1")
	{
		return new EnermyGunBoss1Sprite(respawnX, respawnY, bulletSprites);
	}

	if (enermyName == "finalboss1")
	{
		return new EnermyFinalBoss1Sprite(respawnX, respawnY);
	}

	return nullptr;
}

ObjectSprite* EnermyCreator::createObjectSprite(std::string name, int respawnX, int respawnY)
{
	if (name == "bridge")
	{
		return new ObjectBridge(respawnX, respawnY, 2);
	}

	if (name == "staticweapons")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::S);
	}

	if (name == "staticweaponm")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::M);
	}

	if (name == "staticweaponf")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::F);
	}

	if (name == "staticweaponb")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::B);
	}

	if (name == "staticweaponr")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::R);
	}

	if (name == "staticweaponl")
	{
		return new ObjectStaticWeapon(respawnX, respawnY, BulletTypes::L);
	}

	//capsule weapon
	if (name == "capsuleweapons")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, BulletTypes::S);
	}

	if (name == "capsuleweaponm")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, BulletTypes::M);
	}

	if (name == "capsuleweaponf")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, BulletTypes::F);
	}

	if (name == "capsuleweaponb")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, BulletTypes::B);
	}

	if (name == "capsuleweaponr")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, BulletTypes::R);
	}

	if (name == "capsuleweaponl")
	{
		return new ObjectCapsuleWeapon(respawnX, respawnY, BulletTypes::L);
	}

	return nullptr;
}


Direction EnermyCreator::getAppearDir(std::string name, std :: vector < BulletSprite* >& bulletSprites)
{
	if (name == "bridge")
	{
		return (new ObjectBridge(-100, -100, 2))->getAppearDir();
	}

	//static weapon
	if (name == "staticweapons")
	{
		return (new ObjectStaticWeapon(-100, -100, BulletTypes::S))->getAppearDir();
	}

	if (name == "staticweaponm")
	{
		return (new ObjectStaticWeapon(-100, -100, BulletTypes::M))->getAppearDir();
	}

	if (name == "staticweaponf")
	{
		return (new ObjectStaticWeapon(-100, -100, BulletTypes::F))->getAppearDir();
	}

	if (name == "staticweaponb")
	{
		return (new ObjectStaticWeapon(-100, -100, BulletTypes::B))->getAppearDir();
	}

	if (name == "staticweaponr")
	{
		return (new ObjectStaticWeapon(-100, -100, BulletTypes::R))->getAppearDir();
	}

	if (name == "staticweaponl")
	{
		return (new ObjectStaticWeapon(-100, -100, BulletTypes::L))->getAppearDir();
	}

	//capsule weapon
	if (name == "capsuleweapons")
	{
		return (new ObjectCapsuleWeapon(-100, -100, BulletTypes::S))->getAppearDir();
	}

	if (name == "capsuleweaponm")
	{
		return (new ObjectCapsuleWeapon(-100, -100, BulletTypes::M))->getAppearDir();
	}

	if (name == "capsuleweaponf")
	{
		return (new ObjectCapsuleWeapon(-100, -100, BulletTypes::F))->getAppearDir();
	}

	if (name == "capsuleweaponb")
	{
		return (new ObjectCapsuleWeapon(-100, -100, BulletTypes::B))->getAppearDir();
	}

	if (name == "capsuleweaponr")
	{
		return (new ObjectCapsuleWeapon(-100, -100, BulletTypes::R))->getAppearDir();
	}

	if (name == "capsuleweaponl")
	{
		return (new ObjectCapsuleWeapon(-100, -100, BulletTypes::L))->getAppearDir();
	}

	if (name == "gunrotating")
	{
		return (new EnermyGunRotating(-100, -100))->getAppearDir();
	}

	if (name == "cannon")
	{
		return (new EnermyCannon(-100, -100))->getAppearDir();
	}

    if (name == "soldierl")
	{
        return Direction::createRight();
	}

    if (name == "soldierr")
    {
        return Direction::createLeft();
    }

	if (name == "gunboss1")
	{
		return (new EnermyGunBoss1Sprite(-100, -100, bulletSprites))->getAppearDir();
	}

	if (name == "finalboss1")
	{
		return (new EnermyFinalBoss1Sprite(-100, -100))->getAppearDir();
	}

	if (name == "sniper")
	{
		return (new EnemySniper(-100, -100))->getAppearDir();
	}

	return Direction::createNone();
}