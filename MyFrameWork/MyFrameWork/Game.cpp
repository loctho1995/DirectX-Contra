
#include "Game.h"
#include <vector>
#include "iostream"

Game:: Game()
{
	SceneManager::getInstance() ->createScene(new OptionScene());
}

void Game :: update()
{
	SceneManager::getInstance() ->getCurrentScene() ->onUpdate();
}

void Game :: render()
{
	SceneManager::getInstance() ->getCurrentScene() ->render();
}

