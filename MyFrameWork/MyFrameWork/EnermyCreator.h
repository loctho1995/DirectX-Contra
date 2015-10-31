#pragma once


#include "EnermyInkSprite.h"
#include "EnermySoldier.h"
#include "ObjectBridgeHead.h"
#include "ObjectBridgeBody.h"
#include "ObjectBridgeTail.h"
#include "EnermySprite.h"
#include "ObjectSprite.h"
#include "ObjectStaticWeapon.h"

class EnermyCreator
{
private:
	static EnermyCreator* instance;
	EnermyCreator() {}
public:
	static EnermyCreator* getInstance();
	EnermySprite * createEnermySprite(std::string enermyName, int respawnX, int respawnY );
	ObjectSprite* createObjectSprite(std::string name, int respawnX, int respawnY );

};