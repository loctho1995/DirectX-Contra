#pragma once
#include"EnermySprite.h"
class EnermyScubarSoliderSprite :public EnermySprite
{
public:
	EnermyScubarSoliderSprite(int respawnX, int respawnY,int kind, std::vector < BulletSprite*>& bulletSpriteVector);
	~EnermyScubarSoliderSprite();
	static void loadResources();
	void update();
	void draw(Camera*);
	virtual void playBeShootedEffect();
};