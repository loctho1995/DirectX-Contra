#include "Loader.h"

Loader* Loader::sInstance = nullptr;

Loader* Loader::getInstance()
{
	if (sInstance == nullptr)
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
	if (std::find(spriteNamesLoaded.begin(), spriteNamesLoaded.end(), name) == spriteNamesLoaded.end())
	{
		spriteNamesLoaded.push_back(name);

		if (name == "player")
		{
			PlayerSprite::loadResources();
			return;
		}

		if (name == "gunboss1")
		{
			EnermyGunBoss1Sprite::loadResources();
			return;
		}

		if (name == "cannon")
		{
			EnermyCannon::loadResources();
			return;
		}

		if (name == "finalboss1")
		{
			EnermyFinalBoss1Sprite::loadResources();
			return;
		}

		if (name == "blazer")
		{
			EnemyBlazerSprite::loadResources();
			return;
		}


		if (name == "dynamicbridge")
		{
			ObjectDynamicBridgeSprite::loadResources();
			return;
		}

		if (name == "failingstone")
		{
			EnermyFailingStone::loadResources();
			return;
		}

		if (name == "gunrotating")
		{
			EnermyGunRotating::loadResources();
			return;
		}

		if (name == "scubarsolider")
		{
			BulletScubarSoliderSprite::loadResources();
			return;
		}

	}
}