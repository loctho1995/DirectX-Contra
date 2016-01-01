#pragma once
#include "MenuScene.h"
#include "Texture.h"
class StartingScene : public MenuScene
{
public:
	StartingScene(void);
	~StartingScene(void);
	virtual void onUpdate();
	virtual void render();
	virtual void handleInput();
	void update();
private:
	enum
	{
		PLAYER,
		PLAYER2,
		HELP,
		OPTION,
		HISCORE,
		QUIT,
		COUNT
	} LableIndex;

	Label **label;
	int cursorIndex;
	float startPosY;
	float startPosX; 
	float offsetY;
	float offsetX;
	float xPos;
	float vxPos;
	bool isTransitioning;
	Texture* pBackGround;
	Texture* pCursor;
};

