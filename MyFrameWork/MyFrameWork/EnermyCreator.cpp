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

	addAppearDirection("bridge",Direction::createRight());

	addAppearDirection("staticweapons",Direction::createRight());
	addAppearDirection("staticweaponm",Direction::createRight());
	addAppearDirection("staticweaponf",Direction::createRight());
	addAppearDirection("staticweaponb",Direction::createRight());
	addAppearDirection("staticweaponr",Direction::createRight());
	addAppearDirection("staticweaponl",Direction::createRight());

	addAppearDirection("gunrotating",Direction::createRight());

	addAppearDirection("cannon",Direction::createRight());

	addAppearDirection("soldierl",Direction::createRight());

	addAppearDirection("sniper",Direction::createRight());
	
	addAppearDirection("capsuleweapons",Direction::createLeft());
	addAppearDirection("capsuleweaponm",Direction::createLeft());
	addAppearDirection("capsuleweaponf",Direction::createLeft());
	addAppearDirection("capsuleweaponb",Direction::createLeft());
	addAppearDirection("capsuleweaponr",Direction::createLeft());
	addAppearDirection("capsuleweaponl",Direction::createLeft());

	addAppearDirection("soldierr",Direction::createLeft());


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
		return new EnermyGunRotating(respawnX, respawnY, bulletSprites);
	}

	if (enermyName == "cannon")
	{
		return new EnermyCannon(respawnX, respawnY, bulletSprites);
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
		return new EnemySniper(respawnX, respawnY, bulletSprites);
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


Direction EnermyCreator::getAppearDir(std::string name)
{
	 std::map < std::string, Direction >::iterator it = appearDirections.find(name);
	 if( it != appearDirections.end())
	 {
		 return it -> second;
	 }
	return Direction::createNone();
}