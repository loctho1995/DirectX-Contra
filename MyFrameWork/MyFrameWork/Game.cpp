
#include "Game.h"
#include <vector>
#include "iostream"

Game:: Game()
{
	SceneManager::getInstance() ->createScene(new StartingScene());
}

void Game :: update()
{
    if (!SceneManager::getInstance()->isSceneTransitioning())
    {
        SceneManager::getInstance()->getCurrentScene()->onUpdate();
    }
    else
    {
        SceneTransition::getInstance()->update();
        SceneManager::getInstance()->updateWithEffect();
    }
}

void Game :: render()
{
    if (!SceneManager::getInstance()->isSceneTransitioning())
    {
        SceneManager::getInstance()->getCurrentScene()->render();
    }
}

