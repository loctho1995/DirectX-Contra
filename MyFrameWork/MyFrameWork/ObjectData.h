#pragma once
#include "SpriteData.h"
class ObjectData : public SpriteData 
{
public:
	ObjectData();
	virtual ~ObjectData();
	float playerX;
	float playerY;
	std :: string objectName;
	bool isPlayerCollisionable;
	bool isEnemyCollisionable;
	bool isAffectble;
	int HP;
	Direction appearDir;
};

