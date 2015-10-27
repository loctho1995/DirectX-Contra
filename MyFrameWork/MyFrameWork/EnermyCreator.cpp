#include "EnermyCreator.h"
#include "EnermyInkSprite.h"
#include "EnermyGunBoss1Sprite.h"
#include "EnermyFinalBoss1Sprite.h"
#include "ObjectBridge.h"
#include "EnermyCannon.h"
#include"EnermyGunRotating.h"

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
	if (enermyName == "gunrotating")
	{
		return new EnermyGunRotating(respawnX, respawnY);
	}

	if (enermyName == "cannon")
	{
		return new EnermyCannon(respawnX, respawnY);
	}
    if (enermyName == "soldier")
    {
        return new EnermySoldier(respawnX, respawnY);
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
ObjectSprite* EnermyCreator :: createObjectSprite(std::string name, int respawnX, int respawnY )
{
    if (name == "bridge")
    {
        return new ObjectBridge(respawnX, respawnY, 2);
    }

	return nullptr;
}