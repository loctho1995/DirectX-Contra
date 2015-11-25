#pragma once
#include <string>
#include <vector>
#include <map>
#include "EnermyGunBoss1Sprite.h"
#include "EnermyFinalBoss1Sprite.h"
#include "PlayerSprite.h"
#include "Map.h"
#include "ObjectBridge.h"
#include "Boss2Final.h"

class Loader
{
public:
	~Loader();
	Loader();
	static Loader* getInstance();
	void loadResources(std :: string name);
	void operator()(std :: vector< std:: string> spriteNames, int& loaded)
	{
		for (int i = 0; i < spriteNames.size(); i++)
		{
			loadResources(spriteNames[i]);
			loaded = i + 1;
		}
	}
private:
	
	static Loader* sInstance;
	std::vector<std::string > spriteNamesLoaded;
	std::map< std::string, TextureArray**> arrayMap;
};

