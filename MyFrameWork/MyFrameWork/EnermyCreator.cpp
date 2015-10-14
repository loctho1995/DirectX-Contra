#include "EnermyCreator.h"
#include "EnermyInkSprite.h"
#include "EnermyGunBoss1Sprite.h"
#include "EnermyFinalBoss1Sprite.h"

EnermyCreator* EnermyCreator:: instance = nullptr;
EnermyCreator* EnermyCreator :: getInstance()
{
	if(instance == nullptr)
	{
		instance = new EnermyCreator();
	}
	return instance;
}

EnermySprite* EnermyCreator :: createEnermySprite(std::string enermyName, int respawnX, int respawnY )
{
	if(enermyName == "ink")
	{
		return new EnermyInkSprite ( respawnX, respawnY);
	}
	if( enermyName == "gunboss1" )
	{
		return new EnermyGunBoss1Sprite ( respawnX, respawnY);
	}
	if(enermyName == "finalboss1")
	{
		return new EnermyFinalBoss1Sprite( respawnX, respawnY );
	}
	return nullptr;
}