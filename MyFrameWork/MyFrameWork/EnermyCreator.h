#pragma once


#include "EnermyInkSprite.h"
#include "EnermySoldier.h"
#include "EnermyBridgeHead.h"
#include "EnermyBridgeBody.h"
#include "EnermyBridgeTail.h"


class EnermyCreator
{
private:
	static EnermyCreator* instance;
	EnermyCreator() {}
public:
	static EnermyCreator* getInstance();
	EnermySprite * createEnermySprite(std::string enermyName, int respawnX, int respawnY );

};