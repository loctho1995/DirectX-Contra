#pragma once
#include "EnermySprite.h"
class EnemyBlazerSprite : public EnermySprite
{
public:
	EnemyBlazerSprite(int respawnX, int respawnY);
	~EnemyBlazerSprite();
	static void loadResources();
};

