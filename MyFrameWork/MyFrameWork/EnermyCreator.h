#pragma once

#include "EnermySprite.h"

class EnermyCreator
{
private:
	static EnermyCreator* instance;
	EnermyCreator() {}
public:
	static EnermyCreator* getInstance();
	EnermySprite * createEnermySprite(std::string enermyName, int respawnX, int respawnY );

};