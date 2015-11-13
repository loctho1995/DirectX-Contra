#pragma once
#include "MenuScene.h"
#include "Graphics.h"
class TestScene : public MenuScene
{
public:
	TestScene(void);

	void handleInput() {}
	void onUpdate() {}
	void render();

	~TestScene(void);
};

