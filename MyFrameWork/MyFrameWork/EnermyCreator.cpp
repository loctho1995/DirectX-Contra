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

    if (enermyName == "soldier")
    {
        return new EnermySoldier(respawnX, respawnY);
    }

    if (enermyName == "bridgehead")
    {
        return new EnermyBridgeHead(respawnX, respawnY);
    }

    if (enermyName == "bridgebody")
    {
        return new EnermyBridgeBody(respawnX, respawnY);
    }

    if (enermyName == "bridgetail")
    {
        return new EnermyBridgeTail(respawnX, respawnY);
    }

	return nullptr;
}