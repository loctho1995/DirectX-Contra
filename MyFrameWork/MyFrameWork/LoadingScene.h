#pragma once
#include "MenuScene.h"
#include "Graphics.h"
#include "SceneManager.h"
class LoadingScene : public MenuScene
{
public:
	LoadingScene(void);

	void onUpdate();
	void render();

	~LoadingScene(void);
private:
	int nTransitionTime;
	int count;
};

