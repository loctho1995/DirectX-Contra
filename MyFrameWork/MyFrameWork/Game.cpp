
#include "Game.h"
#include <vector>
#include "iostream"

Game:: Game()
{
	SceneManager::getInstance() ->createScene(new PlayScene(2));
}

void Game :: go()
{
	SceneManager::getInstance() ->getCurrentScene()->go();
}


