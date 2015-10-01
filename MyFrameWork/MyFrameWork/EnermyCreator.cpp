#include "EnermyCreator.h"

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
	// cant not use switch statement
	if(enermyName == "ink")
	{
		return new EnermyInkSprite ( respawnX, respawnY);
	}
	return nullptr;
}