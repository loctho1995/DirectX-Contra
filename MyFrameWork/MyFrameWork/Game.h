#pragma once

#include "SceneManager.h"
#include "SceneTransition.h"
#include "Graphics.h"
#include "Sound.h"

class Game
{

public :
	Game(HWND hWnd);
	~Game()
	{}
	void cleanUp();
	//void go();
	void update();
	void render();
};