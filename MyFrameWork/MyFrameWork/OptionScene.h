#pragma once
#include "MenuScene.h"
#include "SceneManager.h"
class OptionScene : public MenuScene
{
public:
	OptionScene(void);
	virtual ~OptionScene();
	virtual void onUpdate();
	virtual void render();
	void update();
	virtual void handleInput();
private:
	enum
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
		FIRE,
		JUMP,
		DEFAULT,
		VOLUMNE,
		BACK,
		COUNT
	} LableIndex;
	Label tittle;
	Label **label;
	Label **editText;
	int cursorIndex;
	bool isChoosing;
	bool isBack;
};

