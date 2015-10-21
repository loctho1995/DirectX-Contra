#pragma once


#include "EnermyInkSprite.h"
#include "EnermySoldier.h"
#include "EnermyBridgeHead.h"
#include "EnermyBridgeBody.h"
#include "EnermyBridgeTail.h"
#include "EnermySprite.h"
#include "ObjectSprite.h"

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