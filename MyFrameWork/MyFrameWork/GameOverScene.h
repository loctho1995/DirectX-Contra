#pragma once
#include "MenuScene.h"
#include "Graphics.h"
#include "KeyBoard.h"
#include "SceneManager.h"
class GameOverScene : public MenuScene
{
public:
	GameOverScene();

	virtual void onUpdate();
	virtual void render();
	virtual void handleInput();
	~GameOverScene(void);
private:

};

