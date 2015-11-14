#pragma once

#include "Scene.h"

class MenuScene : public Scene
{
public:
	MenuScene() {}
	virtual ~MenuScene() {}
	virtual void onUpdate() = 0;
	virtual void render() = 0;
	virtual void handleInput() {};
};