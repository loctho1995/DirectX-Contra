
#include "Game.h"
#include <vector>
#include "iostream"

Game:: Game()
{
	SceneManager::getInstance() ->createScene(new LoadingScene());
}

void Game :: update()
{
	SceneManager::getInstance() ->getCurrentScene() ->onUpdate();
}

void Game :: render()
{
	SceneManager::getInstance() ->getCurrentScene() ->render();
}

