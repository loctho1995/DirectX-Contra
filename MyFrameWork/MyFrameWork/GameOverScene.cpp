#include "GameOverScene.h"


GameOverScene::GameOverScene()
{
	UIComponents::getInstance() -> gameOverReset();
	Sound::getInstance() -> play("gameOver", false , 1);
}


GameOverScene::~GameOverScene(void)
{

}

void GameOverScene:: onUpdate()
{
	handleInput();
}
void GameOverScene:: render()
{
	Graphics::getInstance()->beginRender();

	Graphics::getInstance() ->getSpriteHandler() -> Begin(D3DXSPRITE_ALPHABLEND	);
	
	Graphics::getInstance() ->drawText("GAME OVER", 5 , 0 , 50);

	Graphics::getInstance() ->drawText("PRESS ENTER TO", 6 , 10 , 100, D3DCOLOR_ARGB(255, 255, 0, 0));

	Graphics::getInstance() ->drawText("PLAY AGAIN DUMB", 6 , 10 , 170, D3DCOLOR_ARGB(255, 255, 0, 0));

	Graphics::getInstance() ->drawText("OR END TO", 6 , 10 , 220, D3DCOLOR_ARGB(255, 255, 0, 0));

	Graphics::getInstance() ->drawText("ESCAPE", 6 , 10 , 270, D3DCOLOR_ARGB(255, 255, 0, 0));

	Graphics::getInstance() ->getSpriteHandler() -> End();

	Graphics::getInstance()->endRender();
}

void GameOverScene:: handleInput()
{
	while (!KeyBoard::getInstace()->isEmpty())
	{
		KeyEvent e = KeyBoard::getInstace()->readKey();
		switch (e.getCode())
		{
		case VK_RETURN:
			if (e.isRelease())
			{
				SceneManager::getInstance() ->createScene( new PlayScene());
			}
			break;
		case VK_END:
			if (e.isRelease())
			{
				SceneManager::getInstance() ->createScene( new StartingScene());
			}
			break;
		}
	}
}
