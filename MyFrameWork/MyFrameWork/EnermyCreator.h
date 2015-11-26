#pragma once

#include "EnermyInkSprite.h"
#include "EnermySoldier.h"
#include "EnemySniper.h"
#include "ObjectBridgeHead.h"
#include "ObjectBridgeBody.h"
#include "ObjectBridgeTail.h"
#include "EnermySprite.h"
#include "ObjectSprite.h"
#include "ObjectStaticWeapon.h"
#include "ObjectCapsuleWeapon.h"
#include "EnemyBazokaSprite.h"
#include <map>


class EnermyCreator
{
private:
	static EnermyCreator* instance;
	EnermyCreator();
	void addAppearDirection(std::string name, Direction dir);
public:
	static EnermyCreator* getInstance();
	EnermySprite * createEnermySprite(std::string enermyName, int respawnX, int respawnY, std :: vector < BulletSprite* >& bulletSprites);
	ObjectSprite* createObjectSprite(std::string name, int respawnX, int respawnY);
	Direction getAppearDir(std::string name);
	std::map < std::string, Direction > appearDirections;
};