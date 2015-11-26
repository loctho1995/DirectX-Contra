#pragma once
#include "EnermySprite.h"
class EnemyBazokaSprite : public EnermySprite
{
public:
	EnemyBazokaSprite(float respawnX, float respawnY, std::vector<BulletSprite*>& bulletVector);
	~EnemyBazokaSprite(void);
	static void loadResources();
};

