#pragma once
#include "MenuScene.h"
class StartingScene : public MenuScene
{
public:
	StartingScene(void);
	~StartingScene(void);
	virtual void onUpdate();
	virtual void render();
	virtual void handleInput();
};

