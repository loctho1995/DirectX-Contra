#pragma once

#include "Scene.h"

class MenuScene : public Scene
{
public:
	MenuScene() {}
	virtual ~MenuScene() {}
	virtual void go()
	{
		handleInput();
		onUpdate();
		render();
	}
	virtual void handleInput() = 0;
};