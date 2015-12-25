#pragma once
#include "MenuScene.h"
#include "Graphics.h"
#include "SceneManager.h"
#include "Loader.h"
#include <thread>
#include "UIComponents.h"
#include "TransitionCircleOpen.h"
#include "TransitionCircleScan.h"
#include "TransitionScan.h"

class LoadingScene : public MenuScene
{
public:
	
	LoadingScene();
	void onUpdate();
	void render();
	~LoadingScene(void);

private:
	enum
	{
		TITLE,
		SCORE,
		LIFES,
		SCORE2,
		LIFES2,
		STAGE,
		COUNT
	} LableIndex;
	int nTransitionTime;
	int count;
	int nSprites;
	int loadedSprite;
	Texture* pBackGround;
	Label **label;
};

