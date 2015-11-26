#pragma once
#include "EnermySprite.h"
class EnemyMineSprite : public EnermySprite
{
public:
	EnemyMineSprite(int respawnX, int respawnY);
	~EnemyMineSprite(void);
	static void loadResources();
};

