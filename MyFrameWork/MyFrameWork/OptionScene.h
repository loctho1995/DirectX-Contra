#pragma once
#include "MenuScene.h"
#include "SceneManager.h"
#include "Sound.h"
#include "Texture.h"
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
		VOLUME,
		DEFAULT,
		BACK,
		COUNT
	} LableIndex;
	Label tittle;
	Label **label;
	Label **editText;
	int cursorIndex;
	bool isChoosing;
	bool isBack;
	float volume;
	float volumeStep;
	Texture* pBackGround;
	Texture* pCursor;
	float startPosY;
	float startPosX; 
	float offsetY;
	float offsetX;
};

