
#include "Game.h"
#include <vector>
#include "iostream"

Game:: Game(HWND hWnd)
{
	Graphics::create(hWnd);
	Sound::create(hWnd);
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

void Game :: cleanUp()
{
	UIComponents::getInstance() -> cleanUp();
	Sound::getInstance() -> cleanUp();
	Graphics::getInstance() -> cleanUp();
}
