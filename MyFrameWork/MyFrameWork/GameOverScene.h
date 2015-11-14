#pragma once
#include "MenuScene.h"
class GameOverScene : public MenuScene
{
public:
	GameOverScene(int stageIndex);

	virtual void onUpdate();
	virtual void render();
	virtual void handleInput();
	~GameOverScene(void);
private:
	int stageIndex;
};

