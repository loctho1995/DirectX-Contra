#pragma once
#include "MenuScene.h"
#include "Graphics.h"
#include "SceneManager.h"
#include "Loader.h"
#include <thread>
class LoadingScene : public MenuScene
{
public:
	
	LoadingScene(int stageIndex);
	void onUpdate();
	void render();
	~LoadingScene(void);

private:
	int nTransitionTime;
	int count;
	int stageIndex;
	int nSprites;
	int loadedSprite;
};

