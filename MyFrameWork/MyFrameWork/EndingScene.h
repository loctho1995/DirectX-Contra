#pragma once
#include "Graphics.h"
#include "MenuScene.h"
#include "KeyBoard.h"
#include "SceneManager.h"
class EndingScene : public MenuScene
{
public:
	EndingScene(void);
	virtual void onUpdate();
	virtual void render();
	virtual void handleInput();
	~EndingScene(void);

private:
    void resetPos();
	Label *label;
    int numOfLabel;
};

