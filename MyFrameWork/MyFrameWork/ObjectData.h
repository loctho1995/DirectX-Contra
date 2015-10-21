#pragma once
#include "SpriteData.h"
class ObjectData : public SpriteData 
{
public:
	ObjectData(void);
	virtual ~ObjectData(void);
	float playerX;
	float playerY;
	std :: string objectName;
	bool isPlayerCollisionable;
	bool isEnemyCollisionable;
	bool isAffectble;
	int HP;
};

