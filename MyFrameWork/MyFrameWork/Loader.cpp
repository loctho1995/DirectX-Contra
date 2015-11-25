#include "Loader.h"

Loader* Loader::sInstance = nullptr;

Loader* Loader:: getInstance()
{
	if(sInstance == nullptr)
	{
		sInstance = new Loader();
	}
	return sInstance;
}
Loader::Loader()
{
}


Loader::~Loader(void)
{
}
void Loader::loadResources(std::string name)
{
	if(std::find(spriteNamesLoaded.begin(), spriteNamesLoaded.end(), name) == spriteNamesLoaded.end())
	{
		spriteNamesLoaded.push_back(name);

		if( name == "player")
		{
			PlayerSprite::loadResources();
			return;
		}

		if (name == "gunboss1")
		{
			EnermyGunBoss1Sprite::loadResources();
			return;
		}

		if (name == "finalboss1")
		{
			EnermyFinalBoss1Sprite::loadResources();
			return;
		}

        if (name == "soldierl" || name == "solderr")
        {
            EnermySoldier::loadResources();
            return;
        }

        if (name == "bridge")
        {
            ObjectBridge::loadResources();
            return;
        }

        if (name == "boss2finalarmleft" || name == "boss2finalarmright" || name == "boss2finalhead")
        {
            Boss2Final::loadResources();
            return;
        }
	}
}